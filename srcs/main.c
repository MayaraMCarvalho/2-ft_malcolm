/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2024/10/24 17:34:38 by macarval         ###   ########.fr       */
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
		if (valid_args(&data))
		{
			welcome();
			setup_signal();
			while (true)
				attack();
		}
	}
	return (0);
}

void	setup(char *argv[], t_data *data)
{
	data->source_ip = argv[1];
	data->source_mac = argv[2];
	data->target_ip = argv[3];
	data->target_mac = argv[4];
}

void	attack(void)
{
}

void	signal_handler(int signal)
{
	if (signal == SIGINT || signal == SIGTERM || signal == SIGTSTP)
	{
		bye();
		exit(0);
	}
}

void	setup_signal(void)
{
	struct sigaction	action;

	ft_memset(&action, 0, sizeof(action));
	action.sa_handler = signal_handler;
	if (sigaction(SIGINT, &action, NULL) == -1
		|| sigaction(SIGTERM, &action, NULL) == -1
		|| sigaction(SIGTSTP, &action, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}
