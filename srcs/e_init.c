/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 02:04:14 by maviot            #+#    #+#             */
/*   Updated: 2017/10/04 05:19:59 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env		*e_init(void)
{
	t_env *e;

	e = ft_memalloc(sizeof(t_env));
	e->zoom = 0;
	e->x_start = XS;
	e->y_start = YS;
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
	e->color = 0;
	set_colors(e);
	return (e);
}

void		set_colors(t_env *e)
{
	int	*tab;

	tab = ft_memalloc(sizeof(int) * 4);
	tab[0] = 0xffffff;
	tab[1] = 0xff0000;
	tab[2] = 0x00ff00;
	tab[3] = 0x0000ff;
	e->colors = tab;
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
		e->zoom = 15;
	else if (e->map_x <= 100 && e->map_y <= 100)
		e->zoom = 5;
	else if (e->map_x <= 200 && e->map_y <= 200)
		e->zoom = 3;
	else if (e->map_x <= 500 && e->map_y <= 500)
		e->zoom = 2;
}
