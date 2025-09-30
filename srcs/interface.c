/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:39:48 by user42            #+#    #+#             */
/*   Updated: 2025/09/27 11:42:02 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	get_index_if(void)
{
	int		index_if;

	index_if = if_nametoindex(g_data.info.if_name);
	if (!index_if)
		fatal_error("Failed to obtain interface index!");

	return (index_if);
}

void	get_name_if(void)
{
	struct ifaddrs	*ifaddr;

	g_data.info.if_name = ft_calloc(IF_NAMESIZE, sizeof(char));
	if (!g_data.info.if_name)
		fatal_error("Memory allocation failed!");

	if (getifaddrs(&ifaddr) == -1)
		fatal_error("Error getting network interfaces!");

	get_name_interface(ifaddr, g_data.info.if_name);
	freeifaddrs(ifaddr);

	if (g_data.info.if_name[0] == '\0')
		fatal_error("No valid network interface found!");
}

void	get_name_interface(struct ifaddrs *ifa, char *name)
{
	while (ifa != NULL)
	{
		if (ifa->ifa_addr != NULL
			&& ifa->ifa_addr->sa_family == AF_PACKET
			&& (ifa->ifa_flags & IFF_UP)
			&& !(ifa->ifa_flags & IFF_LOOPBACK))
		{
			ft_strlcpy(name, ifa->ifa_name, IF_NAMESIZE);
			return ;
		}
		ifa = ifa->ifa_next;
	}
}
