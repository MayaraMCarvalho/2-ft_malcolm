/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:42 by macarval          #+#    #+#             */
/*   Updated: 2024/10/24 12:13:01 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

int main(int argc, char const *argv[])
{
	ft_strlen("Mayara");
	if (argc < 5)
		ft_printf("Error\n");
	else
		ft_printf("%s\n", argv[0]);
	return 0;
}
