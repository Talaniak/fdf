/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 04:11:24 by maviot            #+#    #+#             */
/*   Updated: 2017/09/29 08:27:52 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_exit(t_env *e)
{
		write(1, "\n  Seeya !\n\n", 13);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
}

void		l_r(t_env *e)
{
	if (e->curkey == 123)
	{
		mlx_clear_window(e->mlx, e->win);
		e->l_r--;
		draw_top_down(e);
	}
	if (e->curkey == 124)
	{
		mlx_clear_window(e->mlx, e->win);
		e->l_r++;
		draw_top_down(e);
	}
}

void		u_d(t_env *e)
{
	if (e->curkey == 125)
	{
		mlx_clear_window(e->mlx, e->win);
		e->u_d--;
		draw_top_down(e);
	}
	if (e->curkey == 126)
	{
		mlx_clear_window(e->mlx, e->win);
		e->u_d++;
		draw_top_down(e);
	}	
}

int			check_input(int keycode, t_env *e)
{
	e->curkey = keycode;
	if (e->curkey == 53)
		ft_exit(e);
	if (e->curkey == 123 || e->curkey == 124)
		l_r(e);	
	if (e->curkey == 125 || e->curkey == 126)
		u_d(e);	
	return (0);
}
