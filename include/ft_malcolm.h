/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:05:57 by macarval          #+#    #+#             */
/*   Updated: 2024/10/31 16:33:29 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

# include <stdio.h> // printf
# include <signal.h> // sigaction, signal
# include <arpa/inet.h> // inet_pton, inet_ntop, inet_addr, htons, ntohs
# include <string.h> // strerror
// # include <sys/socket.h> // sendto, recvfrom, socket, setsockopt
# include <net/if.h> // if_nametoindex
// # include <unistd.h> // sleep, getuid, close
// # include <netdb.h> // gethostbyname, getaddrinfo, freeaddrinfo, gai_strerror
// # include <ifaddrs.h> // getifaddrs, freeifaddrs


# include "colors.h"
# include "libft.h"

# define TRUE 1
# define FALSE 0
# define SIZE_MAC 6
# define SIZE_IP 4
# define ETH_P_ARP 0x0806

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

typedef struct s_data
{
	const char		*source_mac;
	const char		*source_ip;
	const char		*target_mac;
	const char		*target_ip;

}	t_data;

// main.c
void	attack(void);
void	signal_handler(int signal);

// info.c
void	welcome(void);
void	bye(void);
int		ip_error(const char *ip);
int		mac_error(const char *mac);

// setup.c
void	setup(char *argv[], t_data *data, t_arp *arp);
void	setup_arp(const char *info, unsigned char *arp, int add);
void	setup_socket(void);
void	setup_signal(void);

// utils.c
int		counter(char **list);

// validations.c
int		valid_args(t_data	*data);
int		valid_ip(const char *ip);
int		valid_mac(const char *mac);

#endif
