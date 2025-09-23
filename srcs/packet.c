/* ************************************************************************ */
/*   packet.c                                                               */
/*                                                         ___  ___ _____   */
/*                                                         |  \/  |/  __ \  */
/*                                                         | .  . || /  \/  */
/*  By: Mayara Carvalho <mayaracarvalhomk@gmail.com>       | |\/| || |      */
/*                                                         | |  | || \__/\  */
/*  Created: 2025/09/18 18:15:42 by Mayara Carvalho        \_|  |_/ \____/  */
/*                                                                          */
/*                                                                          */
/* ************************************************************************ */

#include "ft_malcolm.h"

void	send_packet(void)
{
	struct sockaddr_ll	addr;
	uint8_t				frame[14 + sizeof(t_arp)];


	create_packet();
	create_frame(frame);

	ft_memset(&addr, 0, sizeof(struct sockaddr));
	addr.sll_family = AF_PACKET;
	addr.sll_protocol = htons(ETH_P_ARP);
	addr.sll_ifindex = g_data.if_index;
	addr.sll_halen = ETH_ALEN;
	ft_memcpy(addr.sll_addr, g_data.arp.target_mac, ETH_ALEN);

	if (sendto(g_data.sock_fd, frame, sizeof(frame), 0,
			(struct sockaddr *)&addr, sizeof(struct sockaddr)) == -1)
		fatal_error("Failed to send ARP packet!");
}

void	create_frame(uint8_t *frame)
{
	t_eth_hdr	*eth;
	t_arp		*arp_payload;

	eth = (t_eth_hdr *)frame;
	arp_payload = (t_arp *)(frame + 14);
	ft_memcpy(eth->dst_mac, g_data.arp.target_mac, ETH_ALEN);
	ft_memcpy(eth->src_mac, g_data.arp.sender_mac, ETH_ALEN);
	eth->ethertype = htons(ETH_P_ARP);

	ft_memcpy(arp_payload, &g_data.arp, sizeof(t_arp));
}

void	create_packet(void)
{
	g_data.arp.htype = htons(1);
	g_data.arp.ptype = htons(0x0800);
	g_data.arp.hlen = ETH_ALEN;
	g_data.arp.plen = INET4_LEN;
	g_data.arp.opcode = htons(2);

	ft_memcpy(g_data.arp.target_mac, g_data.arp.target_mac, ETH_ALEN);
	ft_memcpy(g_data.arp.target_ip, g_data.arp.target_ip, INET4_LEN);
}

void	receive_packet (void)
{
	char				buffer[1024];
	struct sockaddr_ll	client_addr;
	socklen_t			addr_len;
	ssize_t				bytes;

	addr_len = sizeof(client_addr);
	bytes = recvfrom(g_data.sock_fd, buffer, sizeof(buffer), 0,
			(struct sockaddr *)&client_addr, &addr_len);

	if (bytes == -1)
		fatal_error("Failed to receive packet!");

	// Excluir depois dos testes
	if (bytes >= 42 && verify_buffer(buffer, 0, 5, 0xff)
		&& buffer[12] == 0x08 && buffer[13] == 0x06
		&& buffer[20] == 0x00 && buffer[21] == 0x01)
	{
		printf("ARP Request de broadcast recebido!\n");

		printf("Received %zd bytes\n", bytes);

		printf("Data: \n");
		print_packet(buffer, 0, bytes - 1, ' ');

		printf("MAC de origem: \n");
		print_packet(buffer, 6, 11, ':');

		printf("IP de origem: \n");
		print_packet(buffer, 28, 31, '.');
	}
}

void print_packet(char *buffer, int init_range, int end_range, char delimeter)
{
	int	i;

	//Validar flag para mudar o print

	if (init_range > end_range)
		return;

	i = init_range - 1;
	while (++i < end_range)
		printf("%02x%c", (uint8_t)buffer[i], delimeter);
	printf("%02x\n", (uint8_t)buffer[i]);
}
