/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:13:28 by maviot            #+#    #+#             */
/*   Updated: 2017/10/03 14:12:12 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		data_to_pix(t_env *e, int x, int y)
{
	int		z;

	z = e->data_map[y][x];
	if (z > 0)
	{
		e->x_pix = (XS + x * e->zoom - (e->zoom * z));
		e->y_pix = (YS + y * e->zoom - (e->zoom * z));
	}
	else
	{
		e->x_pix = XS + x * e->zoom;
		e->y_pix = YS + y * e->zoom;
	}
}

void		line_d(t_env *e, int x, int y)
{
	t_line	*l;

	l = l_init();
	l->xi = e->x_pix;
	l->yi = e->y_pix;
	if (y < e->map_y - 1)
	{
		data_to_pix(e, x, y + 1);
		ligne(e, l, e->x_pix + 0, e->y_pix + 0);
	}
	free(l);
}

void		line_r(t_env *e, int x, int y)
{
	t_line	*l;

	l = l_init();
	l->xi = e->x_pix;
	l->yi = e->y_pix;
	if (x < e->map_x - 1)
	{
		data_to_pix(e, x + 1, y);
		ligne(e, l, e->x_pix + 0, e->y_pix + 0);
	}
	free(l);
}

void		draw(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->map_y)
	{
		j = 0;
		while (j < e->map_x)
		{
			data_to_pix(e, j, i);
			line_r(e, j, i);
			data_to_pix(e, j, i);
			line_d(e, j, i);
			j++;
		}
		i++;
	}
}
