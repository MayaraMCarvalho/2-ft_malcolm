/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:03:28 by macarval          #+#    #+#             */
/*   Updated: 2025/10/13 14:15:30 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	setup(char *argv[])
{
	g_data.info.sock_fd = -1;

	get_name_if();

	set_ip(argv[1], g_data.info.source_ip);
	set_mac(argv[2], g_data.info.source_mac);
	set_ip(argv[3], g_data.info.target_ip);
	set_mac(argv[4], g_data.info.target_mac);
}

void	set_mac(const char *info, uint8_t *mac)
{
	if (!info || sscanf(info, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
			&mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5]) != 6)
	{
		mac_error(info);
		clean_exit();
	}
}

void	set_ip(char *info, uint8_t *ip)
{
	if (inet_pton(AF_INET, info, ip) != 1)
	{
		free(info);
		ip_error(info);
		clean_exit();
	}

	free(info);
}

void	setup_signal(void)
{
	struct sigaction	action;

	ft_memset(&action, 0, sizeof(action));
	action.sa_handler = &signal_handler;
	action.sa_flags = 0;

	if (sigaction(SIGINT, &action, NULL) == -1
		|| sigaction(SIGTERM, &action, NULL) == -1
		|| sigaction(SIGTSTP, &action, NULL) == -1)
		exit(EXIT_FAILURE);
}
