/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:05:57 by macarval          #+#    #+#             */
/*   Updated: 2025/10/13 17:43:32 by macarval         ###   ########.fr       */
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
#include <net/ethernet.h>

// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/ioctl.h>
// #include <bits/sigaction.h>
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
# define ETH_LEN 14

typedef struct __attribute__((packed)) s_arp
{
	uint16_t	htype;					// Hardware type (1 for Ethernet)
	uint16_t	ptype;					// Protocol type (0x0800 for IP)
	uint8_t		hlen;					// Hardware address length (MAC)
	uint8_t		plen;					// Protocol address length (IP)
	uint16_t	opcode;					// Operation (1 for request/2 for reply)
	uint8_t		sender_mac[ETH_ALEN];	// Sender hardware address (MAC)
	uint8_t		sender_ip[INET4_LEN];	// Sender protocol address (IP)
	uint8_t		target_mac[ETH_ALEN];	// Target hardware address (MAC)
	uint8_t		target_ip[INET4_LEN];	// Target protocol address (IP)
}	t_arp;

typedef struct __attribute__((packed))
{
	uint8_t		dst_mac[ETH_ALEN];
	uint8_t		src_mac[ETH_ALEN];
	uint16_t	ethertype;
}	t_eth;

typedef struct s_info
{
	uint8_t		source_mac[ETH_ALEN];
	uint8_t		source_ip[INET4_LEN];
	uint8_t		target_mac[ETH_ALEN];
	uint8_t		target_ip[INET4_LEN];
	int			has_flag;
	int			sock_fd;
	char		*if_name;
}	t_info;


typedef struct s_data
{
	t_info		info;
	t_arp		arp;
	t_eth		eth;
}	t_data;

extern t_data g_data;

// main.c
void	connection(void);
void	attack(void);
void	signal_handler(int signal);

// errors.c
int		ip_error(const char *ip);
int		mac_error(const char *mac);
void	fatal_error(char *msg);
void	clean_exit(void);

// info.c
void	welcome(void);
void	bye(void);
void	print_log(const char *msg, const char *title, ssize_t size, char *buf);
void	print_address(const uint8_t  *buf, int init, int end, char delimeter);

// interface.c
int		get_index_if(void);
void	get_name_if(void);
void	get_name_interface(struct ifaddrs *ifa, char *name);

// reply.c
void	reply_packet(void);
void	setup_device(struct sockaddr_ll *addr);
void	setup_packet(void);

// request.c
int		request_packet(void);
int		received_request(ssize_t bytes, char *buffer);
int		verify_buffer(char *buffer, int init_range, int end_range, char byte);
void	print_request_verbose(t_arp *arp);
void	print_request(t_arp *arp);

// setup.c
void	setup(char *argv[]);
void	set_mac(const char *info, uint8_t *mac);
void	set_ip(char *info, uint8_t *ip);
void	setup_signal(void);

// utils.c
int		count_args(char **args);
int		is_hex(const char *str);
char	*get_ip(const char *hostname);

// validations.c
int		validate_data(int argc, char *argv[]);
int		validate_ip(const char *ip);
int		validate_mac(const char *mac);
int		validate_flag(const char *flag);
int		validate_spoofed_ip(void);

#endif
