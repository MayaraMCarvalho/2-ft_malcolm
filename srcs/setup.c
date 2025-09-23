/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:03:28 by macarval          #+#    #+#             */
/*   Updated: 2025/09/23 15:00:28 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	setup(char *argv[])
{
	set_ip(argv[1], g_data.arp.sender_ip);
	set_mac(argv[2], g_data.arp.sender_mac);
	set_ip(argv[3], g_data.arp.target_ip);
	set_mac(argv[4], g_data.arp.target_mac);
}

void	set_mac(const char *info, uint8_t *mac)
{
	char	**list;
	int		i;

	i = -1;
	list = ft_split(info, ':');
	while (list[++i])
		sscanf(list[i], "%2hhx", &mac[i]);

	free_split(&list);
}

void	set_ip(const char *info, uint8_t *ip)
{
	char	**list;
	int		i;

	i = -1;
	list = ft_split(info, '.');
	while (list[++i])
		sscanf(list[i], "%hhu", &ip[i]);

	free_split(&list);
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
