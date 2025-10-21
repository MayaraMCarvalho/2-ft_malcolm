/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:56 by macarval          #+#    #+#             */
/*   Updated: 2025/10/21 11:34:45 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	validate_data(int argc, char *argv[])
{
	char	*flag;

	flag = NULL;
	if (argc == 6)
		flag = argv[5];

	g_data.info.has_flag = FALSE;

	argv[1] = get_ip(argv[1]);
	argv[3] = get_ip(argv[3]);

	if (!validate_ip(argv[1]) || !validate_ip(argv[3])
		|| !validate_mac(argv[2]) || !validate_mac(argv[4])
		|| !validate_flag(flag))
		return (FALSE);

	return (TRUE);
}

int	validate_ip(const char *ip)
{
	char	**list;
	int		i;
	int		num;
	int		error;
	char	dummy;

	list = ft_split(ip, '.');
	if (!list)
		return (ip_error(ip));

	error = (count_args(list) != 4);
	i = -1;
	while (!error && list[++i])
	{
		if (sscanf(list[i], "%d%c", &num, &dummy) != 1
			|| num < 0 || num > 255)
			error = TRUE;
	}
	free_split(&list);

	if (error)
		return (ip_error(ip));

	return (TRUE);
}

int	validate_mac(const char *mac)
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

int	validate_flag(const char *flag)
{
	if (flag)
	{
		if (ft_strlen(flag) != 2 || flag[0] != '-' || flag[1] != 'v')
		{
			printf("%s", RED);
			printf("ft_malcolm: invalid flag (%s)\n", flag);
			printf("%s", RESET);

			return (FALSE);
		}
		g_data.info.has_flag = TRUE;
	}

	return (TRUE);
}
