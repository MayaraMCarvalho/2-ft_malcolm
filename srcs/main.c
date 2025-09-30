/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/27 11:41:18 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

t_data	g_data;

int	main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("%sError: insufficient argument number!\n", RED);
		printf("\nUsage: ft_malcolm <Source IP> <Source MAC Address>");
		printf(" <Target IP> <Target MAC Address> [Flag optional]: -v%s\n\n",
			RESET);
		return (0);
	}
	if (validate_data(argc, argv))
	{
		setup_signal();
		setup(argv);
		attack();
	}
	return (0);
}

void	attack(void)
{
	welcome();
	connection();
	while (1)
	{
		if (request_packet())
		{
			reply_packet();
			break ;
		}
	}
	if (g_data.info.sock_fd >= 0)
		close(g_data.info.sock_fd);

	if (g_data.info.if_name)
		free(g_data.info.if_name);

	bye();
}

void	signal_handler(int signal)
{
	if (signal == SIGINT || signal == SIGTERM || signal == SIGTSTP)
	{
		if (g_data.info.sock_fd >= 0)
			close(g_data.info.sock_fd);

		if (g_data.info.if_name)
			free(g_data.info.if_name);

		exit(0);
	}
}
