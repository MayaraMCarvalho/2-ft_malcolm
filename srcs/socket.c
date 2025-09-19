/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:39:48 by user42            #+#    #+#             */
/*   Updated: 2025/09/19 17:34:01 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	connection(void)
{
	struct sockaddr_ll	sock_addr;

	g_data.if_index = get_index_if();
	g_data.sock_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
	if (g_data.sock_fd < 0)
		fatal_error("ft_malcolm: failed to get socket descriptor!");

	ft_memset(&sock_addr, 0, sizeof(struct sockaddr));
	sock_addr.sll_family = AF_PACKET;
	sock_addr.sll_protocol = htons(ETH_P_ARP);
	sock_addr.sll_ifindex = g_data.if_index;
	sock_addr.sll_halen = ETH_ALEN;

	if (bind(g_data.sock_fd, (struct sockaddr *)&sock_addr, sizeof(struct sockaddr)) < 0)
		fatal_error("ft_malcolm: bind failed!");
}

int	get_index_if(void)
{
	int		index_if;
	char	*name;

	name = get_name_if();
	index_if = if_nametoindex(name);
	free(name);
	if (!index_if)
		fatal_error("ft_malcolm: failed to obtain interface index!");

	return (index_if);
}

char	*get_name_if(void)
{
	struct ifaddrs	*ifaddr;
	char			*name;

	if (getifaddrs(&ifaddr) == -1)
		fatal_error("ft_malcolm: error getting network interfaces!");

	name = ft_calloc(IF_NAMESIZE, sizeof(char));
	if (!name)
	{
		freeifaddrs(ifaddr);
		fatal_error("ft_malcolm: memory allocation failed!");
	}

	get_name_interface(ifaddr, name);
	freeifaddrs(ifaddr);

	if (name[0] == '\0')
	{
		free(name);
		fatal_error("ft_malcolm: no valid network interface found!");
	}

	return (name);
}

void get_name_interface(struct ifaddrs *ifa, char *name)
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
