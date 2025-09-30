/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/27 15:41:04 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	print_log(const char *msg, const char *title, ssize_t size, char *buf)
{
	int	i;

	if (!(g_data.info.has_flag))
		return ;

	printf("[VERBOSE] %s\n", msg);
	printf("\n[VERBOSE] %s (%ld bytes)\n", title, size);

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
			printf("%02d%c", (uint8_t)buf[i], delimeter);
		printf("%02d\n", (uint8_t)buf[i]);
	}
}
