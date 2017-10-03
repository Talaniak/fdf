/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 02:04:14 by maviot            #+#    #+#             */
/*   Updated: 2017/10/03 14:15:22 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env		*e_init(void)
{
	t_env *e;

	e = ft_memalloc(sizeof(t_env));
	e->zoom = 0;
	e->map_x = 0;
	e->map_y = 0;
	e->max_x = 0;
	e->max_y = 0;
	e->x = 0;
	e->y = 0;
	e->z = 0;
	e->x_pix = 0;
	e->y_pix = 0;
	e->l_r = 10;
	e->u_d = 10;
	return (e);
}

t_line		*l_init(void)
{
	t_line *l;

	l = ft_memalloc(sizeof(t_line));
	l->xi = 0;
	l->yi = 0;
	l->xf = 0;
	l->yf = 0;
	l->dx = 0;
	l->dy = 0;
	l->i = 0;
	l->xinc = 0;
	l->yinc = 0;
	l->cumul = 0;
	l->x = 0;
	l->y = 0;
	return (l);
}

void		set_zoom(t_env *e)
{
	if (e->map_x <= 20 && e->map_y <= 20)
	{
		printf("petit\n");
		e->zoom = 15;
	}
	else if (e->map_x <= 100 && e->map_y <= 100)
	{
		printf("GRAND\n");
		e->zoom = 3;
	}
	else if (e->map_x <= 200 && e->map_y <= 200)
	{
		printf("GRAND\n");
		e->zoom = 2;
	}
	else if (e->map_x <= 500 && e->map_y <= 500)
	{
		printf("GRAND\n");
		e->zoom = 1;
	}
}
