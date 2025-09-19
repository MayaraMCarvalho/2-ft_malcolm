/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:05:57 by macarval          #+#    #+#             */
/*   Updated: 2025/09/19 18:17:43 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

# include <stdio.h> // printf
# include <netdb.h> // gethostbyname, getaddrinfo, freeaddrinfo, gai_strerror
# include <errno.h>
# include <string.h> // strerror
# include <net/if.h> // if_nametoindex
# include <signal.h> // sigaction, signal
# include <unistd.h> // sleep, getuid, close
# include <ifaddrs.h> // getifaddrs, freeifaddrs
# include <arpa/inet.h> // inet_pton, inet_ntop, inet_addr, htons, ntohs
# include <sys/socket.h> // sendto, recvfrom, socket, setsockopt
# include <linux/if_arp.h>

// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/ioctl.h>
// #include <bits/sigaction.h>
// #include <net/ethernet.h>
// #include <linux/if_ether.h>
// #include <netinet/ip.h>
// #include <bits/ioctls.h>

# include "libft.h"
# include "colors.h"

# define TRUE 1
# define FALSE 0

# define ETH_P_ARP 0x0806
# define INET4_LEN 4
# define ETH_ALEN 6

typedef struct __attribute__((packed)) s_arp
{
	uint16_t	htype;			// Hardware type (1 for Ethernet)
	uint16_t	ptype;			// Protocol type (0x0800 for IP)
	uint8_t		hlen;			// Hardware address length (MAC)
	uint8_t		plen;			// Protocol address length (IP)
	uint16_t	opcode;			// Operation (1 for request/2 for reply)
	uint8_t		sender_mac[ETH_ALEN];	// Sender hardware address (MAC)
	uint8_t		sender_ip[INET4_LEN];	// Sender protocol address (IP)
	uint8_t		target_mac[ETH_ALEN];	// Target hardware address (MAC)
	uint8_t		target_ip[INET4_LEN];	// Target protocol address (IP)
}	t_arp;

typedef struct __attribute__((packed)) s_eth_hdr
{
	uint8_t dst_mac[ETH_ALEN];
	uint8_t src_mac[ETH_ALEN];
	uint16_t ethertype;
}	t_eth_hdr;

typedef struct s_data
{
	const char	*source_mac;
	const char	*source_ip;
	const char	*target_mac;
	const char	*target_ip;
	int			sock_fd;
	int			if_index;
	t_arp		arp;
}	t_data;

extern t_data g_data;

// main.c
void	attack(void);
void	signal_handler(int signal);

// info.c
void	welcome(void);
void	bye(void);
int		ip_error(const char *ip);
int		mac_error(const char *mac);
void	fatal_error(char *msg);

// packet.c
void	send_packet(void);
void	create_frame(uint8_t *frame);
void	create_packet(void);
void	receive_packet (void);
void	print_packet(char *buffer, int init_range, int end_range, char delimeter);

// setup.c
void	setup(char *argv[]);
void	set_mac(const char *info, uint8_t *mac);
void	set_ip(const char *info, uint8_t *ip);
void	setup_signal(void);

// socket.c
void	connection(void);
int		get_index_if(void);
char	*get_name_if(void);
void	get_name_interface(struct ifaddrs *ifa, char *name);

// utils.c
int		count_args(char **args);
int		is_hex(const char *str);

// validations.c
int		valid_data(void);
int		valid_ip(const char *ip);
int		valid_mac(const char *mac);
int		verify_buffer(char *buffer, int init_range, int end_range, char byte);

#endif
