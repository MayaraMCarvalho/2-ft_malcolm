/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/18 17:30:15 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	g_sock_fd = -1;

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 5)
	{
		printf("%sError: insufficient argument number!\n", RED);
		printf("\nUsage: ft_malcolm <Source IP> <Source MAC Address>");
		printf(" <Target IP> <Target MAC Address>%s\n\n", RESET);
	}
	else
	{
		setup(argv, &data);
		if (valid_data(&data))
		{
			welcome();
			connection();
			setup_signal();
			while (TRUE)
				attack(&data);
		}
	}
	return (0);
}

void	attack(t_data *data)
{
	create_packet(data->target_mac);
	receive_packet();
}

void	create_packet(const char *target_mac)
{
	int				sent;
	unsigned char	packet[42];
	t_addr			addr;

	memset(&addr, 0, sizeof(addr));
	addr.sll_family = AF_PACKET;
	addr.sll_protocol = htons(ETH_P_ARP);
	addr.sll_ifindex = get_index_if();
	addr.sll_halen = ETH_ALEN;
	memcpy(addr.sll_addr, target_mac, 6);

	sent = sendto(g_sock_fd, packet, sizeof(packet), 0,
			(struct sockaddr *)&addr, sizeof(addr));

	if (sent == -1)
		fatal_error("ft_malcolm: sendto failed!");
}

void	receive_packet (void)
{
	char		buffer[1024];
	t_addr		client_addr;
	socklen_t	addr_len = sizeof(client_addr);
	ssize_t		bytes;

	bytes = recvfrom(g_sock_fd, buffer, sizeof(buffer), 0,
			(struct sockaddr *)&client_addr, &addr_len);

	buffer[bytes] = '\0';
	printf("Received %zd bytes\nBuffer: %s\n", bytes, buffer);
}

void	signal_handler(int signal)
{
	if (signal == SIGINT || signal == SIGTERM || signal == SIGTSTP)
	{
		close(g_sock_fd);
		bye();
		exit(0);
	}
}
