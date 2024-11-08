/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2024/11/08 12:15:59 by user42           ###   ########.fr       */
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
				attack();
		}
	}
	return (0);
}

void	attack(void)
{
	// Resto do seu código...

	// Montar pacotes
	// sendto(g_sock_fd, packet, packet_size, 0, (struct sockaddr *)&addr, sizeof(addr));
	// recvfrom(g_sock_fd, buffer, sizeof(buffer), 0, NULL, NULL);
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
