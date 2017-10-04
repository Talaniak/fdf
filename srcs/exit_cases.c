/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 04:56:20 by maviot            #+#    #+#             */
/*   Updated: 2017/10/04 01:39:58 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		my_exit(int ac)
{
	if (ac < 2)
	{
		write(2, "I can't do anything without a map..\n", 37);
	}
	if (ac > 2)
	{
		write(2, "Hey chill, I can't handle more than one map at a time\n", 55);
	}
	exit(0);
}

void		map_err(void)
{
	write(2, "map error, can only accept digits and spaces\n", 46);
	exit(0);
}

void		ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}
