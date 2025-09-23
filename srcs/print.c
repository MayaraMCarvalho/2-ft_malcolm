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

void	print_packet(char *buffer, int init_range, int end_range, char delimeter)
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

void	print_request(ssize_t bytes, char *buffer)
{
	if (bytes >= 42 && verify_buffer(buffer, 0, 5, 0xff)
		&& buffer[12] == 0x08 && buffer[13] == 0x06
		&& buffer[20] == 0x00 && buffer[21] == 0x01)
	{
		printf("***Broadcast ARP Request received***\n");

		printf("Received %zd bytes\n", bytes);

		printf("Data: \n");
		print_packet(buffer, 0, bytes - 1, ' ');

		printf("MAC de origem: \n");
		print_packet(buffer, 6, 11, ':');

		printf("IP de origem: \n");
		print_packet(buffer, 28, 31, '.');
	}
}
