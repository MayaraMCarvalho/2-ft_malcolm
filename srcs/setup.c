/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:03:28 by macarval          #+#    #+#             */
/*   Updated: 2024/11/05 15:00:36 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	setup(char *argv[], t_data *data)
{
	data->source_ip = argv[1];
	data->source_mac = argv[2];
	data->target_ip = argv[3];
	data->target_mac = argv[4];
	set_mac(data->source_mac, data->arp.sha);
	set_ip(data->source_ip, data->arp.spa);
	set_mac(data->target_mac, data->arp.tha);
	set_ip(data->target_ip, data->arp.tpa);
}

void	set_mac(const char *info, unsigned char *mac)
{
	char	**list;
	int		i;

	i = -1;
	list = ft_split(info, ':');
	while (list[++i])
		sscanf(list[i], "%hhx", &mac[i]);
	free_split(&list);
}

void	set_ip(const char *info, unsigned char *ip)
{
	char	**list;
	int		i;

	i = -1;
	list = ft_split(info, '.');
	while (list[++i])
		sscanf(list[i], "%hhi", &ip[i]);
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
		// exit(EXIT_FAILURE);
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
