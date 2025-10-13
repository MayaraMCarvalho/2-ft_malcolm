/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:51:28 by macarval          #+#    #+#             */
/*   Updated: 2025/10/13 12:20:45 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

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

	clean_exit();
}

void	clean_exit(void)
{
	if (g_data.info.sock_fd >= 0)
		close(g_data.info.sock_fd);
	if (g_data.info.if_name)
		free(g_data.info.if_name);

	bye();
	exit(EXIT_FAILURE);
}

