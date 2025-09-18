/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:05:57 by macarval          #+#    #+#             */
/*   Updated: 2025/09/18 18:16:35 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

# include <stdio.h> // printf
# include <signal.h> // sigaction, signal
# include <arpa/inet.h> // inet_pton, inet_ntop, inet_addr, htons, ntohs
# include <string.h> // strerror
# include <ifaddrs.h> // getifaddrs, freeifaddrs
# include <net/if.h> // if_nametoindex

# include <sys/socket.h> // sendto, recvfrom, socket, setsockopt
# include <unistd.h> // sleep, getuid, close
# include <netdb.h> // gethostbyname, getaddrinfo, freeaddrinfo, gai_strerror

# include "libft.h"
# include "colors.h"

# define TRUE 1
# define FALSE 0
# define SIZE_MAC 6
# define SIZE_IP 4

# define ETH_P_ARP 0x0806
# define ETH_ALEN 6

extern int	g_sock_fd;

typedef struct s_arp
{
	unsigned short	htype;
	unsigned short	ptype;
	unsigned char	hlen;
	unsigned char	plen;
	unsigned short	oper;
	unsigned char	sha[SIZE_MAC];
	unsigned char	spa[SIZE_IP];
	unsigned char	tha[SIZE_MAC];
	unsigned char	tpa[SIZE_IP];
}	t_arp;

/*
	htype	-> Hardware type
	ptype	-> Protocol type
	hlen	-> Hardware address length
	plen	-> Protocol address length
	oper	-> Operation (request/reply)
	sha		-> Sender hardware address
	spa		-> Sender protocol address
	tha		-> Target hardware address
	tpa		-> Target protocol address
*/

typedef struct s_addr
{
	unsigned short	sll_family;
	unsigned short	sll_protocol;
	int				sll_ifindex;
	unsigned short	sll_hatype;
	unsigned char	sll_pkttype;
	unsigned char	sll_halen;
	unsigned char	sll_addr[8];
}	t_addr;

/*
	sll_family	-> Always AF_PACKET
	sll_protocol-> Protocol (e.g., ETH_P_ARP)
	sll_ifindex	-> Network interface index
	sll_hatype	-> Hadware address type
	sll_pkttype	-> Packet type
	sll_halen	-> Hardware address length
	sll_addr	-> Hardware (MAC) address
*/

typedef struct s_data
{
	const char		*source_mac;
	const char		*source_ip;
	const char		*target_mac;
	const char		*target_ip;
	int				if_index;
	t_arp			arp;
}	t_data;

// main.c
void	attack(t_data *data);
void	signal_handler(int signal);

// info.c
void	welcome(void);
void	bye(void);
int		ip_error(const char *ip);
int		mac_error(const char *mac);
void	fatal_error(char *msg);

// packet.c
void	send_packet(t_data *data);
void	create_packet(unsigned char* packet, t_data *data);
void	receive_packet (void);

// setup.c
void	setup(char *argv[], t_data *data);
void	set_mac(const char *info, unsigned char *mac);
void	set_ip(const char *info, unsigned char *ip);
void	setup_signal(void);

// socket.c
void	connection(t_data *data);
int		get_index_if(void);
char	*get_name_if(void);
void	get_name_interface(struct ifaddrs *ifa, char *name);

// utils.c
int		count_args(char **args);
int		is_hex(const char *str);

// validations.c
int		valid_data(t_data	*data);
int		valid_ip(const char *ip);
int		valid_mac(const char *mac);

#endif
