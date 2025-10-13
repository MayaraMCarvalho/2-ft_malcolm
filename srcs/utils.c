/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:24:35 by macarval          #+#    #+#             */
/*   Updated: 2025/10/13 17:43:47 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	count_args(char **args)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (args && args[++i])
		size++;

	return (size);
}

int	is_hex(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 'a' && str[i] <= 'f')
				|| (str[i] >= 'A' && str[i] <= 'F')))
			return (FALSE);
	}

	return (TRUE);
}

char	*get_ip(const char *hostname)
{
	struct hostent	*host;
	char			ip[INET_ADDRSTRLEN];
	char			*res;

	host = gethostbyname(hostname);
	if (!host)
	{
		ip_error(hostname);
		exit(4);
	}

	inet_ntop(AF_INET, host->h_addr_list[0], ip, sizeof(ip));
	res = ft_strdup(ip);

	return (res);
}
