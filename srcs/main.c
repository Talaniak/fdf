/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 22:19:09 by maviot            #+#    #+#             */
/*   Updated: 2017/10/03 14:14:12 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		my_exit(ac);
	e = e_init();
	e->mlx = mlx_init();
	parser(e, av);
	e->win = mlx_new_window(e->mlx, 1280, 1280, av[1]);
	draw(e);
	mlx_hook(e->win, 2, 3, &check_input, e);
	mlx_loop(e->mlx);
	return (0);
}
