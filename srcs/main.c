/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 22:19:09 by maviot            #+#    #+#             */
/*   Updated: 2017/09/28 06:10:35 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void line(t_param *param, int x0, int y0, int x1, int y1)
{
	int dx;
	int	sx;
	int dy;
	int	sy;
	int err;
	int e2;
	
	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1; 
	err = (dx>dy ? dx : -dy) / 2;

	while (x0 != x1 && y0 != y1)
	{
		mlx_pixel_put(param->mlx, param->win, x0, y0, 0x55ff0000);
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void		draw_top_down(t_param *param)
{
	int		x;
	int		y;
	int		z;
	int		max_x;
	int		max_y;
	int		dist;

	int		xx;
	int		yx;
	//line 2
	int		xy;
	int		yy;
	//line 3
	int		xz;
	int		yz;

	dist = param->map_x + param->map_y;
	y = dist;
	max_x = 0;
	max_y = 0;
	while (max_y < param->map_y)
	{
		x = dist * 20; //l_r
		max_x = 0;
		while (max_x < param->map_x)
		{
			z = param->data_map[max_y][max_x];
			mlx_pixel_put(param->mlx, param->win, (x - y), (((x + y) / 2) - (z * 30)), 0xffffff);
			// line 1
			xx = (x - y) + dist;
			yx = (((x + (y - 30)) / 2) - (z * 30)) + dist;
			//line 2
			xy = (x - y) + dist;
			yy = (((x + (y - 90)) / 2) - (z * 30)) + dist;
			//line 3
			xz = (x - y) + dist;
			yz = ((((x+param->u_d) + (y + param->l_r)) / 2) - (z * 30)) + dist;
			line(param, (x - y), (((x + y) / 2) - (z * 30)), xx, yx);
			line(param, (x - y), (((x + y) / 2) - (z * 30)), xy, yy);
	//		printf("max_x = %d, max_y = %d\n", max_x, max_y);
			printf("param[%d][%d] = %d\n", max_x, max_y, param->data_map[max_x][max_y]);
			if (z > 0)
			{
				printf("in\n");
				line(param, (x - y), (((x + y) / 2) - (z * 30)), xz, yz);	
			}
			x += dist;
			max_x++;
		}
		y += dist;
		max_y++;
	}
}

int			chk_exit(int keycode, t_param *param)
{
	param->curkey = keycode;
	if (keycode == 53)
	{
		write(1, "\n  Seeya !\n\n", 13);
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	if (keycode == 123)
	{
		mlx_clear_window(param->mlx, param->win);	
		param->l_r--;
		draw_top_down(param);
	}
	if (keycode == 124)
	{
		mlx_clear_window(param->mlx, param->win);	
		param->l_r++;
		draw_top_down(param);
	}
	if (keycode == 125)
	{
		mlx_clear_window(param->mlx, param->win);	
		param->u_d = param->u_d + 50;
		draw_top_down(param);
	}
	if (keycode == 126)
	{
		mlx_clear_window(param->mlx, param->win);	
		param->u_d = param->u_d - 50;
		draw_top_down(param);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_param	*param;

	if (ac != 2)
	{
		my_exit(ac);
	}
	param = malloc(sizeof(t_param));
	param->l_r = 2;
	param->u_d = 700;
	param->mlx = mlx_init();
	get_x_y(param, av);
	get_z(param, av);
	param->win = mlx_new_window(param->mlx,
			param->map_x * 80, param->map_y * 80, "myWindow");
	draw_top_down(param);
	printf("x = %d, y = %d\n", param->map_x, param->map_y);
	mlx_hook(param->win, 2, 3, &chk_exit, param);
	mlx_loop(param->mlx);
	return (0);
}
