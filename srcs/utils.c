/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:24:35 by macarval          #+#    #+#             */
/*   Updated: 2025/09/18 13:09:15 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	count_args(char **args)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (args[++i])
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
