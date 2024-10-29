/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:05:57 by macarval          #+#    #+#             */
/*   Updated: 2024/10/29 14:46:49 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

# include <stdio.h> // printf
# include <signal.h> // sigaction, signal
// # include <sys/socket.h> // sendto, recvfrom, socket, setsockopt
// # include <arpa/inet.h> // inet_pton, inet_ntop, inet_addr, htons, ntohs
// # include <net/if.h> // if_nametoindex
// # include <unistd.h> // sleep, getuid, close
// # include <netdb.h> // gethostbyname, getaddrinfo, freeaddrinfo, gai_strerror
// # include <ifaddrs.h> // getifaddrs, freeifaddrs
// # include <string.h> // strerror

# include "colors.h"
# include "libft.h"

# define TRUE 1
#define FALSE 0


typedef struct s_data
{
	const char	*source_ip;
	const char	*source_mac;
	const char	*target_ip;
	const char	*target_mac;
}	t_data;

// main.c
void	setup(char *argv[], t_data *data);
void	attack(void);
void	setup_signal(void);
void	signal_handler(int signal);

// info.c
void	welcome(void);
void	bye(void);
int		ip_error(const char *ip);
int		mac_error(const char *mac);

// utils.c
int		counter(char **list);

// validations.c
int		valid_args(t_data	*data);
int		valid_ip(const char *ip);
int		valid_mac(const char *mac);

#endif
