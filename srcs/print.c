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

int	print_request(ssize_t bytes, char *buffer)
{
	if (bytes >= (ssize_t)(ETH_LEN + sizeof(t_arp))
		&& verify_buffer(buffer, 0, 5, 0xff)
		&& buffer[12] == 0x08 && buffer[13] == 0x06)
	{
		t_arp *arp;

		arp = (t_arp *)(buffer + ETH_LEN);
		if (ntohs(arp->opcode) == 1
			&& memcmp(arp->sender_ip, g_data.info.target_ip, INET4_LEN) == 0
			&& memcmp(arp->target_ip, g_data.info.source_ip, INET4_LEN) == 0)
		{
			printf("Found available interface: %s\n", g_data.info.if_name);
			printf("An ARP request has been broadcast.\n");

			printf("\tmac address of request: ");
			print_packet(arp->sender_mac, 0, 5, ':');

			printf("\tIP address of request: ");
			print_packet(arp->sender_ip, 0, 3, '.');

			return (1);
		}
	}

	return (0);
}

void	print_packet(const uint8_t *buffer, int init, int end, char delimeter)
{
	int	i;

	//Validar flag para mudar o print
	if (init > end || init < 0)
		return;

	if (delimeter == ':')
	{
		for (i = init; i < end; ++i)
			printf("%02x%c", (uint8_t)buffer[i], delimeter);
		printf("%02x\n", (uint8_t)buffer[i]);
	}
	else if (delimeter == '.')
	{
		for (i = init; i < end; ++i)
			printf("%02d%c", (uint8_t)buffer[i], delimeter);
		printf("%02d\n", (uint8_t)buffer[i]);
	}
}


