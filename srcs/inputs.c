/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 04:11:24 by maviot            #+#    #+#             */
/*   Updated: 2017/10/04 05:46:36 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_exit(t_env *e)
{
	write(1, "\n  Seeya !\n\n", 13);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

void		u_d(t_env *e)
{
	if (e->curkey == 125)
	{
		e->x_start += 20;
		e->y_start += 20;
	}
	if (e->curkey == 126)
	{
		e->x_start -= 20;
		e->y_start -= 20;
	}
}

void		l_r(t_env *e)
{
	if (e->curkey == 123)
	{
		e->x_start -= 20;
		e->y_start += 20;
	}
	if (e->curkey == 124)
	{
		e->x_start += 20;
		e->y_start -= 20;
	}
}

void		p_m(t_env *e)
{
	if (e->curkey == 78 && e->zoom > 3)
		e->zoom--;
	if (e->curkey == 69 && e->zoom < 30)
		e->zoom++;
	if (e->curkey == 82 || e->curkey == 83 ||
			e->curkey == 84 || e->curkey == 85)
	{
		if (e->curkey == 82)
			e->color = 0;
		if (e->curkey == 83)
			e->color = 1;
		if (e->curkey == 84)
			e->color = 2;
		if (e->curkey == 85)
			e->color = 3;
	}
}

int			check_input(int keycode, t_env *e)
{
	e->curkey = keycode;
	mlx_clear_window(e->mlx, e->win);
	if (e->curkey == 53)
		ft_exit(e);
	if (e->curkey == 123 || e->curkey == 124)
		l_r(e);
	if (e->curkey == 125 || e->curkey == 126)
		u_d(e);
	if (e->curkey == 69 || e->curkey == 78 || e->curkey == 82 ||
			e->curkey == 83 || e->curkey == 84 || e->curkey == 85)
		p_m(e);
	draw(e);
	return (0);
}
