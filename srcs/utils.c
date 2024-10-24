/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:24:35 by macarval          #+#    #+#             */
/*   Updated: 2024/10/24 16:53:31 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	counter(char **list)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (list[++i])
		size++;
	return (size);
}
