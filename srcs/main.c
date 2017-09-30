/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 22:19:09 by maviot            #+#    #+#             */
/*   Updated: 2017/09/30 06:23:59 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void line(t_env *e, int x0, int y0, int x1, int y1)
{
	t_line *l;

	l = ft_memalloc(sizeof(t_line));	
	l->dx = abs(x1 - x0);
	l->sx = x0 < x1 ? 1 : -1;
	l->dy = abs(y1 - y0);
	l->sy = y0 < y1 ? 1 : -1; 
	l->err = (l->dx > l->dy ? l->dx : -l->dy) / 2;

	while (x0 != x1 && y0 != y1)
	{
		mlx_pixel_put(e->mlx, e->win, x0, y0, 0xffffff);
		l->e2 = l->err;
		if (l->e2 >- l->dx)
		{
			l->err -= l->dy;
			x0 += l->sx;
		}
		if (l->e2 < l->dy)
		{
			l->err += l->dx;
			y0 += l->sy;
		}
	}
}

void		set_y(t_env *e)
{
	e->lya = (((e->x + e->y) / 2) - (e->z * (e->u_d * 2))) + e->zoom;
}

void		set_x(t_env *e)
{
	e->lxa = (e->x - e->y) + e->zoom;
}

void		draw_top_down(t_env *e)
{
	e->y = 400;
	e->max_y = 0;
	while (e->max_y < e->map_y)
	{
		e->max_x = 0;
		e->x = 800;
		while (e->max_x < e->map_x)
		{
			e->z = e->data_map[e->max_y][e->max_x];
			set_x(e); //lines
			set_y(e); //lines
//			mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0xffffff);
//			mlx_pixel_put(e->mlx, e->win, (e->x - e->y), (((e->x + e->y) / 2) - (e->z * (e->u_d * 2))), 0xffffff);
			mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0xffffff);
			line(e, (e->x - e->y), (((e->x + e->y) / 2) - (e->z * (e->u_d * 2))), e->lxa, e->lya);	
//			printf("x = %d, y = %d, x0 = %d, y0 = %d\n", (e->x - e->y), (((e->x + e->y) / 2) - (e->z * (e->u_d * 2))), e->lxa, e->lya);
			e->max_x++;
			e->x += e->zoom;
		}
		e->max_y++;
		e->y += e->zoom;
	}
}

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		my_exit(ac);
	e = e_init();
	e->mlx = mlx_init();
	parser(e, av);
	e->win = mlx_new_window(e->mlx, 1280, 1280, av[1]);
	draw_top_down(e);
	printf("map_x = %d, map_y = %d\n", e->map_x, e->map_y);
/*	
	int a = 0;
	int b = 0;
	while (a < e->map_y)
	{
		b = 0;
		while (b < e->map_x)
		{
			printf("%d ", e->data_map[a][b]);
			b++;
		}
		printf("\n");
		a++;
	}
*/
	mlx_hook(e->win, 2, 3, &check_input, e);
	mlx_loop(e->mlx);
	return (0);
}
