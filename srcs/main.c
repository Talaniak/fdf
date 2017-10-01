/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 22:19:09 by maviot            #+#    #+#             */
/*   Updated: 2017/09/30 09:10:55 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ligne(t_env *e, int xi,int yi,int xf,int yf) {
  int dx,dy,i,xinc,yinc,cumul,x,y ;
  x = xi ;
  y = yi ;
  dx = xf - xi ;
  dy = yf - yi ;
  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  dx = abs(dx) ;
  dy = abs(dy) ;
 // mlx_pixel_put(e->mlx, e->win, x, y, 0xffffff);
mlx_pixel_put(e->mlx, e->win, (x - y), ((y + x) / 2), 0xffffff);
  if ( dx > dy ) 
{
    cumul = dx / 2 ;
    for ( i = 1 ; i <= dx ; i++ ) 
	{
      x += xinc ;
      cumul += dy ;
      if ( cumul >= dx ) 
	{
        cumul -= dx ;
        y += yinc ; 
	}
//      mlx_pixel_put(e->mlx, e->win, x, y, 0xffffff);
mlx_pixel_put(e->mlx, e->win, (x - y), ((y + x) / 2), 0xffffff);
       } 
}
    else 
	{
    cumul = dy / 2 ;
    for ( i = 1 ; i <= dy ; i++ ) 
	{
      y += yinc ;
      cumul += dx ;
      if ( cumul >= dy ) 
	{
        cumul -= dy ;
        x += xinc ; 
	}
    //  mlx_pixel_put(e->mlx, e->win, x, y, 0xffffff);
	mlx_pixel_put(e->mlx, e->win, (x - y), ((y + x) / 2), 0xffffff);
	}
	}
}
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



void		draw_top_down(t_env *e)
{
	e->y = 400;
	e->max_y = 0;
	while (e->max_y < e->map_y)
	{
		e->max_x = 0;
		e->x = 600;
		while (e->max_x < e->map_x)
		{
			e->z = e->data_map[e->max_y][e->max_x];
			if (e->z > 0)
			{
				if (e->z == e->data_map[e->max_y][e->max_x + 1] && e->x != e->map_x)
					line(e, (e->x - e->z * e->l_r), (e->y - e->z * e->l_r), ((e->x + e->zoom * 2) - e->z * e->l_r), ((e->y + 1) - (e->z * e->l_r)));	

				if (e->z == e->data_map[e->max_y + 1][e->max_x] && e->y != e->map_y)
					line(e, (e->x - e->z * e->l_r), (e->y - e->z * e->l_r), ((e->x + 1) - e->z * e->l_r), ((e->y + (e->zoom * 2)) - (e->z * e->l_r)));
			
				
				line(e, (e->x - e->z * e->l_r), (e->y - e->z * e->l_r), (e->x + e->zoom), (e->y + e->zoom));
			}
			else
			{	
				if ((e->max_x != (e->map_x - 1)) && (e->z == e->data_map[e->max_y][e->max_x + 1])) 
					line(e, e->x, e->y, (e->x + e->zoom * 2), (e->y + 1));	
				if ((e->max_y != (e->map_y - 1)) && (e->z == e->data_map[e->max_y][e->max_x + 1]))
					line(e, e->x, e->y, (e->x + 1), (e->y + (e->zoom * 2)));
			}
			e->max_x++;
			e->x += e->zoom;
		}
		e->max_y++;
		e->y += e->zoom;
	}
}

void		data_to_pix(t_env *e, int x, int y)
{
	int z;
	
	z = e->data_map[y][x];
	
	if (z > 0)
	{	
		e->x_pix = (XS + x * e->zoom - (e->zoom * z));
		e->y_pix = (YS + y * e->zoom - (e->zoom * z));
	}
	else
	{
//		printf("in - x = %d, y =%d \n", x, y);
		e->x_pix = XS + x * e->zoom;
		e->y_pix = YS + y * e->zoom;
	}
}

void		line_d(t_env *e, int x, int y)
{
	int xt;
	int yt;

	xt = e->x_pix;
	yt = e->y_pix;

	
	if (y < e->map_y - 1)
	{
		data_to_pix(e, x, y + 1);
//		printf("D x = %d, y = %d xt = %d yt = %d e->x_pix = %d e->y_pix = %d\n", x, y, xt, yt, e->x_pix, e->y_pix);
		ligne(e, xt, yt, e->x_pix + 0, e->y_pix + 0);
	}
}

void		line_r(t_env *e, int x, int y)
{
	int xt;
	int yt;

	xt = e->x_pix;
	yt = e->y_pix;

	if (x < e->map_x - 1)
	{
//		printf("x = %d, y = %d\n", x, y);
		data_to_pix(e, x + 1, y);
//		printf(" R x = %d, y = %d xt = %d yt = %d e->x_pix = %d e->y_pix = %d\n", x, y, xt, yt, e->x_pix, e->y_pix);
		ligne(e, xt, yt, e->x_pix + 0, e->y_pix + 0);
	}
}

int			main(int ac, char **av)
{
	t_env	*e;

	int i = 0;
	int j = 0;

	if (ac != 2)
		my_exit(ac);
	e = e_init();
	e->mlx = mlx_init();
	parser(e, av);
	e->win = mlx_new_window(e->mlx, 1280, 1280, av[1]);
//	printf("map_x = %d, map_y = %d\n", e->map_x, e->map_y);
	while (i < e->map_y)
//	while (i < 1)
	{
		j = 0;
		while (j < e->map_x)
//		while (j < 1)
		{
			data_to_pix(e, j, i);
			mlx_pixel_put(e->mlx, e->win, e->x_pix + 300, e->y_pix + 200, 0xffffff);
	//		printf("j = %d i = %d e->x_pix = %d e->y_pix =  %d\n", j, i, e->x_pix, e->y_pix);
			line_r(e, j, i);
			data_to_pix(e, j, i);
			line_d(e, j, i);
			j++;
		}
		i++;
	}
	mlx_hook(e->win, 2, 3, &check_input, e);
	mlx_loop(e->mlx);
	return (0);
}
