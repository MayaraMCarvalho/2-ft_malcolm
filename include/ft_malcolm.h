/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:05:57 by macarval          #+#    #+#             */
/*   Updated: 2024/10/30 14:26:50 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

# include <stdio.h> // printf
# include <signal.h> // sigaction, signal
// # include <sys/socket.h> // sendto, recvfrom, socket, setsockopt
# include <arpa/inet.h> // inet_pton, inet_ntop, inet_addr, htons, ntohs
// # include <net/if.h> // if_nametoindex
// # include <unistd.h> // sleep, getuid, close
// # include <netdb.h> // gethostbyname, getaddrinfo, freeaddrinfo, gai_strerror
// # include <ifaddrs.h> // getifaddrs, freeifaddrs
// # include <string.h> // strerror

# include "colors.h"
# include "libft.h"

# define TRUE 1
#define FALSE 0

struct arphdr
{
	unsigned short htype; // Hardware type
	unsigned short ptype; // Protocol type
	unsigned char hlen; // Hardware address length
	unsigned char plen; // Protocol address length
	unsigned short oper; // Operation (request/reply)
	unsigned char sha[6]; // Sender hardware address
	unsigned char spa[4]; // Sender protocol address
	unsigned char tha[6]; // Target hardware address
	unsigned char tpa[4]; // Target protocol address
};

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
	void	setup(char *argv[], t_data *data);
	void	setup_mac(const char *info, unsigned char *mac);
	void	setup_ip(const char *info, unsigned char *ip);
	void	setup_socket(void);
	void	setup_signal(void);

// utils.c
	int		counter(char **list);

// validations.c
	int		valid_args(t_data	*data);
	int		valid_ip(const char *ip);
	int		valid_mac(const char *mac);

extern struct arphdr	g_arp;

#endif
