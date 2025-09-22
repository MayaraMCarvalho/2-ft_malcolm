/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/22 18:04:16 by macarval         ###   ########.fr       */
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
		printf(" <Target IP> <Target MAC Address> [Flag]:optional%s\n\n", RESET);
	}
	else
	{
		setup(argv, argc);
		if (valid_data())
		{
			welcome();
			connection();
			setup_signal();
			attack();
		}
	}
	return (0);
}

void	attack(void)
{
	receive_packet();
	send_packet();
}

void	signal_handler(int signal)
{
	if (signal == SIGINT || signal == SIGTERM || signal == SIGTSTP)
	{
		close(g_data.sock_fd);
		bye();
		exit(0);
	}
}
