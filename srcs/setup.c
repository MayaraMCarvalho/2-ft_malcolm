/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:03:28 by macarval          #+#    #+#             */
/*   Updated: 2024/10/31 17:14:24 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	setup(char *argv[], t_data *data, t_arp *arp)
{
	data->source_ip = argv[1];
	data->source_mac = argv[2];
	data->target_ip = argv[3];
	data->target_mac = argv[4];
	setup_arp(data->source_mac, arp->sha, SIZE_MAC);
	setup_arp(data->source_ip, arp->spa, SIZE_IP);
	setup_arp(data->target_mac, arp->tha, SIZE_MAC);
	setup_arp(data->target_ip, arp->tpa, SIZE_IP);
}

void	setup_arp(const char *info, unsigned char *arp, int add)
{
	char	**list;
	int		i;
	char	c;
	char	*type;

	c = ':';
	type = "%hhx";
	if (add == SIZE_IP)
	{
		c = '.';
		type = "%hhi";
	}
	i = -1;
	list = ft_split(info, c);
	while (list[++i])
		sscanf(list[i], type, &arp[i]);
	free_split(&list);
}

void	setup_socket(void)
{
	int		sock_fd;

	sock_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
	//Instalar máquina virtual a partir daqui.
	
	if (sock_fd < 0)
	{
		printf("%s ft_malcolm: Socket creation failed!%s\n", RED, RESET);
		exit(EXIT_FAILURE);
	}
	printf("Socket aberto!\n");
	// Montar pacotes
	// sendto(sock_fd, packet, packet_size, 0, (struct sockaddr *)&addr, sizeof(addr));
	// recvfrom(sock_fd, buffer, sizeof(buffer), 0, NULL, NULL);
}

void	setup_signal(void)
{
	struct sigaction	action;

	ft_memset(&action, 0, sizeof(action));
	action.sa_handler = signal_handler;
	if (sigaction(SIGINT, &action, NULL) == -1
		|| sigaction(SIGTERM, &action, NULL) == -1
		|| sigaction(SIGTSTP, &action, NULL) == -1)
		exit(EXIT_FAILURE);
}
