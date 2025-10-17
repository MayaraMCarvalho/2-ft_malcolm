/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2025/10/16 21:05:28 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int	request_packet(void)
{
	char				buffer[1024];
	struct sockaddr_ll	client_addr;
	socklen_t			addr_len;
	ssize_t				bytes;
	int					received;

	addr_len = sizeof(client_addr);
	bytes = recvfrom(g_data.info.sock_fd, buffer, sizeof(buffer), 0,
			(struct sockaddr *)&client_addr, &addr_len);

	if (bytes == -1)
		fatal_error("Failed to receive packet!");

	received = received_request(bytes, buffer);

	return (received);
}

int	received_request(ssize_t bytes, char *buffer)
{
	t_arp	*arp;

	if (bytes >= (ssize_t)(ETH_LEN + sizeof(t_arp))
		&& verify_buffer(buffer, 0, 5, 0xff)
		&& buffer[12] == 0x08 && buffer[13] == 0x06)
	{
		arp = (t_arp *)(buffer + ETH_LEN);
		if (arp->hlen != ETH_ALEN || arp->plen != INET4_LEN)
			return (FALSE);
		if (ntohs(arp->opcode) == 1
			&& memcmp(arp->sender_ip, g_data.info.target_ip, INET4_LEN) == 0
			&& memcmp(arp->target_ip, g_data.info.source_ip, INET4_LEN) == 0)
		{
			if (g_data.info.has_flag)
			{
				print_log("***Packet received***", "Raw packet dump", bytes, buffer);
				print_request_verbose(arp);
			}
			else
				print_request(arp);
			return (TRUE);
		}
	}
	return (FALSE);
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

void	print_request_verbose(t_arp *arp)
{
	printf("\n[VERBOSE] Opcode offset: %d → %d\n",
		ETH_LEN + 6, ntohs(arp->opcode));

	printf("[VERBOSE] Sender IP: ");
	print_address(arp->sender_ip, 0, 3, '.');

	printf("[VERBOSE] Target IP: ");
	print_address(arp->target_ip, 0, 3, '.');
}

void	print_request(t_arp *arp)
{
	printf("Found available interface: %s\n", g_data.info.if_name);
	printf("An ARP request has been broadcast.\n");

	printf("\tmac address of request: ");
	print_address(arp->sender_mac, 0, 5, ':');
	g_data.info.target_mac = arp->sender_mac;

	printf("\tIP address of request: ");
	print_address(arp->sender_ip, 0, 3, '.');
}
