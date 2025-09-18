/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:39:48 by user42            #+#    #+#             */
/*   Updated: 2025/09/18 15:26:16 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	connection(void)
{
	t_addr	sock_addr;

	g_sock_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
	if (g_sock_fd < 0)
		fatal_error("ft_malcolm: socket creation failed!");
	ft_memset(&sock_addr, 0, sizeof(t_addr));
	sock_addr.sll_family = AF_PACKET;
	sock_addr.sll_protocol = htons(ETH_P_ARP);
	sock_addr.sll_ifindex = get_index_if();
	sock_addr.sll_halen = ETH_ALEN;
	if (bind(g_sock_fd, (struct sockaddr *)&sock_addr, sizeof(t_addr)) < 0)
		fatal_error("ft_malcolm: bind failed!");
}

int	get_index_if(void)
{
	int		index_if;
	char	*name;

	name = get_name_if();
	index_if = if_nametoindex(name);
	free(name);
	if (index_if == 0)
		fatal_error("ft_malcolm: if_nametoindex failed!");
	return (index_if);
}

char	*get_name_if(void)
{
	struct ifaddrs	*ifaddr;
	struct ifaddrs	*ifa;
	char			*name;

	if (getifaddrs(&ifaddr) == -1)
		fatal_error("ft_malcolm: getifaddrs failed!");
	name = ft_calloc(IF_NAMESIZE, sizeof(char));
	ifa = ifaddr;
	while (ifa != NULL)
	{
		if (ifa->ifa_addr != NULL && ifa->ifa_addr->sa_family == AF_PACKET
			&& (ifa->ifa_flags & IFF_UP) && !(ifa->ifa_flags & IFF_LOOPBACK))
		{
			ft_strlcpy(name, ifa->ifa_name, IF_NAMESIZE);
			freeifaddrs(ifaddr);
			return (name);
		}
		ifa = ifa->ifa_next;
	}
	freeifaddrs(ifaddr);
	if (!name)
		fatal_error("ft_malcolm: get_name_if failed!");
	return (name);
}
