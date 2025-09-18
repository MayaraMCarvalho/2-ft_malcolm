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

void	send_packet(t_data *data)
{
	unsigned char	packet[42];
	t_addr			addr;

	create_packet(packet, data);

	memset(&addr, 0, sizeof(addr));
	addr.sll_family = AF_PACKET;
	addr.sll_protocol = htons(ETH_P_ARP);
	addr.sll_ifindex = data->if_index;
	addr.sll_halen = ETH_ALEN;
	memcpy(addr.sll_addr, data->target_mac, 6);

	if (sendto(g_sock_fd, packet, sizeof(packet), 0,
			(struct sockaddr *)&addr, sizeof(addr)) == -1)
		fatal_error("ft_malcolm: sendto failed!");
}

void create_packet(unsigned char* packet, t_data *data)
{
	memcpy(packet, data->target_mac, 6);
	memcpy(packet + 6, data->source_mac, 6);

	packet[12] = 0x08;
	packet[13] = 0x06;
	packet[14] = 0x00;
	packet[15] = 0x01;
	packet[16] = 0x08;
	packet[17] = 0x00;
	packet[18] = 6;
	packet[19] = 4;
	packet[20] = 0x00;
	packet[21] = 0x01;

	memcpy(packet + 22, data->source_mac, 6);
	memcpy(packet + 28, data->source_ip, 4);
	memcpy(packet + 32, data->target_mac, 6);
	memcpy(packet + 38, data->target_ip, 4);
}

void	receive_packet (void)
{
	char		buffer[1024];
	t_addr		client_addr;
	socklen_t	addr_len = sizeof(client_addr);
	ssize_t		bytes;

	bytes = recvfrom(g_sock_fd, buffer, sizeof(buffer), 0,
			(struct sockaddr *)&client_addr, &addr_len);

	if (bytes == -1)
		fatal_error("ft_malcolm: recvfrom failed!");

	// Excluir depois dos testes
	printf("Received %zd bytes\n", bytes);
	printf("Data: \n");
	for (ssize_t i = 0; i < bytes; ++i)
		printf("%02x ", (unsigned char)buffer[i]);
	printf("\n");
}
