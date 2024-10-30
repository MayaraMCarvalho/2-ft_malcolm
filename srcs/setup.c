/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:03:28 by macarval          #+#    #+#             */
/*   Updated: 2024/10/30 17:06:42 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	setup(char *argv[], t_data *data)
{
	data->source_ip = argv[1];
	data->source_mac = argv[2];
	data->target_ip = argv[3];
	data->target_mac = argv[4];
	setup_mac(data->source_mac, g_arp.sha);
	setup_ip(data->source_ip, g_arp.spa);
	setup_mac(data->target_mac, g_arp.tha);
	setup_ip(data->target_ip, g_arp.tpa);
}

void	setup_mac(const char *info, unsigned char *mac)
{
	char	**list;
	int		i;
	// char	new_mac[6];

	i = -1;
	list = ft_split(info, ':');
	while (list[++i])
		printf("mac[%i]: %s\n", i, list[i]);
		// new_mac[i] = (char)list[i];
	// ft_strlcpy((char *)mac, new_mac, 6);
	if(mac)
	{}
	free_split(&list);
}

void	setup_ip(const char *info, unsigned char *ip)
{
	char	**list;
	int		i;

	i = -1;

	list = ft_split(info, '.');
	while (list[++i])
	{
		ip[i] = ft_atoi(list[i]);
	}
	printf("ip: %hhn\n", ip);
	free_split(&list);
}

void	setup_socket(void)
{
	// int		sock_fd;

	// sock_fd = socket(AF_INET, SOCK_STREAM, htons(ETH_P_ARP));
	// if (sockfd < 0)
	// {
	// 	strerror("socket creation failed");
	// 	exit(EXIT_FAILURE);
	// }

	// // Montar pacotes

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

