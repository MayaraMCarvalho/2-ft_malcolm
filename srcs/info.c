/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:51:52 by macarval          #+#    #+#             */
/*   Updated: 2025/09/27 11:41:38 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	welcome(void)
{
	printf("%s", BYELLOW);
	printf("┎┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈୨♡୧┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┒\n");
	printf("%s", BPURPLE);
	printf("	   __ _                       _           _\n");
	printf("	  / _| |_     _ __ ___   __ _| | ___ ___ | |_ __ ___\n");
	printf("	 | |_| __|   | '_ ` _ \\ / _` | |/ __/ _ \\| | '_ ` _ \\\n");
	printf("	 |  _| |_    | | | | | | (_| | | (_| (_) | | | | | | |\n");
	printf("	 |_|  \\__|___|_| |_| |_|\\__,_|_|\\___\\___/|_|_| |_| |_|\n");
	printf("	        |_____|\n");
	printf("%s", BYELLOW);
	printf("┖┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈୨♡୧┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┚\n");
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

int	ip_error(const char *ip)
{
	printf("%s", RED);
	printf("ft_malcolm: unknown host or invalid IP address (%s)\n", ip);
	printf("%s", RESET);

	return (FALSE);
}

int	mac_error(const char *mac)
{
	printf("%s", RED);
	printf("ft_malcolm: invalid mac address (%s)\n", mac);
	printf("%s", RESET);

	return (FALSE);
}

void	fatal_error(char *msg)
{
	int	err;

	err = errno;
	fprintf(stderr, "\n\n%sft_malcolm: %s%s (%s)\n\n%s",
		YELLOW, RED, msg, strerror(err), RESET);

	if (g_data.info.sock_fd >= 0)
		close(g_data.info.sock_fd);
	if (g_data.info.if_name)
		free(g_data.info.if_name);

	bye();
	exit(EXIT_FAILURE);
}
