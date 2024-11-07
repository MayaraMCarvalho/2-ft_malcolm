/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:24:35 by macarval          #+#    #+#             */
/*   Updated: 2024/11/07 08:26:46 by macarval         ###   ########.fr       */
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
