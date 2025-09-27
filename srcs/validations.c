/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:56 by macarval          #+#    #+#             */
/*   Updated: 2025/09/27 11:39:07 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	valid_data(int argc, char *argv[])
{
	if (argc == 6)
		g_data.info.flag = argv[5];

	if (!valid_ip(argv[1]) || !valid_ip(argv[3])
		|| !valid_mac(argv[2]) || !valid_mac(argv[4])
		|| !valid_flag(g_data.info.flag))
		return (FALSE);

	return (TRUE);
}

int	valid_ip(const char *ip)
{
	char	**list;
	int		i;
	int		num;
	int		error;

	list = ft_split(ip, '.');
	if (!list)
		return (ip_error(ip));

	error = (count_args(list) != 4);
	i = -1;
	while (!error && list[++i])
	{
		char dummy;
		if (sscanf(list[i], "%d%c", &num, &dummy) != 1
			|| num < 0 || num > 255)
			error = TRUE;
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

	if (ft_strlen(mac) != 17)
		return (mac_error(mac));

	list = ft_split(mac, ':');
	if (!list)
		return (mac_error(mac));

	error = (count_args(list) != 6);

	i = -1;
	while (!error && list[++i])
		error = (ft_strlen(list[i]) != 2 || !is_hex(list[i]));

	free_split(&list);
	if (error)
		return (mac_error(mac));

	return (TRUE);
}

int	verify_buffer(char *buffer, int init_range, int end_range, char byte)
{
	int	i;

	if (init_range > end_range)
		return (FALSE);

	i = init_range - 1;
	while (++i <= end_range)
	{
		if (buffer[i] != byte)
			return (FALSE);
	}
	return (TRUE);
}

int	valid_flag(const char *flag)
{
	if (flag && (ft_strlen(flag) != 2
		|| flag[0] != '-' || flag[1] != 'v'))
	{
		printf("%s", RED);
		printf("ft_malcolm: invalid flag (%s)\n", flag);
		printf("%s", RESET);

		return (FALSE);
	}
	return (TRUE);
}
