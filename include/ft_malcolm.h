/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:05:57 by macarval          #+#    #+#             */
/*   Updated: 2024/10/24 17:27:41 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

# include <stdio.h>
# include <stdbool.h>
# include <signal.h>

# include "colors.h"
# include "libft.h"

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
void	setupSignalHandlers(void);
void	signalHandler(int signal);
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
