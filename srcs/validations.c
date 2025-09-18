/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:56 by macarval          #+#    #+#             */
/*   Updated: 2025/09/18 17:24:29 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	valid_data(t_data	*data)
{
	if (!valid_ip(data->source_ip) || !valid_ip(data->target_ip)
		|| !valid_mac(data->source_mac) || !valid_mac(data->target_mac))
		return (FALSE);

	return (TRUE);
}

int	valid_ip(const char *ip)
{
	char	**list;
	int		i;
	int		num;
	int		error;

	error = FALSE;
	list = ft_split(ip, '.');
	error = (count_args(list) < 4);
	i = -1;
	while (!error && list[++i])
	{
		num = ft_atoi(list[i]);
		error = (num < 0 || num > 255);
	}

	free_split(&list);
	if (error)
		return (ip_error(ip));

	return (TRUE);
}

int	valid_mac(const char *mac)
{
	char	**list;
	int		i;
	int		error;

	error = FALSE;
	if (ft_strlen(mac) != 17)
		return (mac_error(mac));

	list = ft_split(mac, ':');
	error = (count_args(list) < 6);
	i = -1;
	while (!error && list[++i])
		error = (ft_strlen(list[i]) != 2 || !is_hex(list[i]));

	free_split(&list);
	if (error)
		return (mac_error(mac));

	return (TRUE);
}
