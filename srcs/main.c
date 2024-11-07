/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2024/11/07 08:22:06 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

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
			setup_socket();
			setup_signal();
			while (TRUE)
				attack();
		}
	}
	return (0);
}

void	attack(void)
{
}

void	signal_handler(int signal)
{
	if (signal == SIGINT || signal == SIGTERM || signal == SIGTSTP)
	{
		// close(sock_fd);
		bye();
		exit(0);
	}
}
