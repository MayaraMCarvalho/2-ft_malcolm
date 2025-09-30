/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:51:52 by macarval          #+#    #+#             */
/*   Updated: 2025/09/30 15:59:34 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	welcome(void)
{
	printf("%s", BYELLOW);
	printf("┎┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈୨♡୧┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┒\n");
	printf("%s", BPURPLE);
	printf("	   __ _                       _           _\n");
	printf("	  / _| |_     _ __ ___   __ _| | ___ ___ | |_ __ ___\n");
	printf("	 | |_| __|   | '_ ` _ \\ / _` | |/ __/ _ \\| | '_ ` _ \\\n");
	printf("	 |  _| |_    | | | | | | (_| | | (_| (_) | | | | | | |\n");
	printf("	 |_|  \\__|___|_| |_| |_|\\__,_|_|\\___\\___/|_|_| |_| |_|\n");
	printf("	        |_____|\n");
	printf("%s", BYELLOW);
	printf("┖┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈୨♡୧┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┚\n");
	printf("%s", RESET);
}

void	bye(void)
{
	printf("\n%sExiting program...%s\n", GREEN, RESET);
	printf("\n%s", BCYAN);
	printf("		 ⠀⠀⠀⠀⠀⠀⠀⠀⣠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⠀⢰⡿⠻⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⢀⣿⠁⠀⠈⠻⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⣼⡇⠀⠀⠀⠀⠹⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⢰⣿⡇⠀⠀⠀⠀⠀⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⢸⡟⣿⣦⣀⠀⣀⣼⠁⣿⣿⠀⠲⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⢸⡇⠈⢛⣿⠿⢿⣿⡄⠘⢻⡇⠀⢹⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠘⡇⣴⠋⠀⠀⣀⠈⠙⣄⠈⡇⠀⢰⠀⣀⠤⠐⠶⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⠹⣇⢰⣷⣾⠷⢶⣤⡘⣤⠇⠀⠞⠋⠀⠀⣀⣠⣤⣴⣶⣶⣶⣶⣦⣤⣀⡀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⣿⣧⣄⡀⠙⣿⣿⣠⡟⢀⡤⠒⠉⠉⠉⠉⠛⣫⠟⠋⠉⠉⠉⠛⠻⢿⣶⣄\n");
	printf("		⠀⠀⠀⢀⣤⣶⣾⣿⣿⠶⠿⠿⢦⣙⣦⣿⣿⣿⣾⣟⣉⡉⠉⠙⠶⣶⣿⡇⠀⠀⠀⠀⠀⠀⢀⣴⡿⠁\n");
	printf("		⠀⢀⣴⣿⣿⣿⣟⣁⣀⣀⣤⠔⢒⣿⣿⣿⣿⠿⣍⡀⠉⠻⣶⡆⠀⠘⣿⣷⣄⠀⠀⠀⣀⣴⠿⠋⠀⠀\n");
	printf("		⢠⡾⠋⠁⠀⢹⣿⡿⠋⣡⣏⠤⠋⣱⡿⢻⡟⡓⢦⣽⣦⣴⣿⣧⠂⢠⡏⠙⠻⢿⣿⣿⠟⠁⠀⠀⠀⠀\n");
	printf("		⣿⣧⣤⣤⣤⣾⡯⠤⠚⠋⠁⠀⢰⠟⠀⡞⢀⡇⠈⢿⡟⠯⣭⣤⣴⣋⣠⡤⠶⠛⠉⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠀⠀⣧⠊⣧⠀⢸⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠇⣰⣿⣧⣸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⡿⠟⠻⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡇⠀⠀⢸⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣄⣠⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠏⠀⠀⠀⠀⠀\n\n");
	printf("%s", RESET);
}

void	print_log(const char *msg, const char *title, ssize_t size, char *buf)
{
	int	i;

	printf("\n[VERBOSE] %s\n", msg);
	printf("[VERBOSE] %s (%zd bytes)\n", title, size);

	for (i = 0; i < size; i++)
	{
		printf("%02x ", (unsigned char)buf[i]);
		if ((i + 1) % 16 == 0)
			printf("\n");
	}
	if (i % 16 != 0)
		printf("\n");
}

void	print_address(const uint8_t *buf, int init, int end, char delimeter)
{
	int	i;

	if (init > end || init < 0)
		return ;

	if (delimeter == ':')
	{
		for (i = init; i < end; ++i)
			printf("%02x%c", (uint8_t)buf[i], delimeter);
		printf("%02x\n", (uint8_t)buf[i]);
	}
	else if (delimeter == '.')
	{
		for (i = init; i < end; ++i)
			printf("%d%c", (uint8_t)buf[i], delimeter);
		printf("%d\n", (uint8_t)buf[i]);
	}
}
