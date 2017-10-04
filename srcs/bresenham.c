/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:01:49 by maviot            #+#    #+#             */
/*   Updated: 2017/10/04 05:35:38 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

void	ligne_deux(t_env *e, t_line *l)
{
	l->cumul = l->dy / 2;
	l->i = 1;
	while (l->i <= l->dy)
	{
		l->y += l->yinc;
		l->cumul += l->dx;
		if (l->cumul >= l->dy)
		{
			l->cumul -= l->dy;
			l->x += l->xinc;
		}
		mlx_pixel_put(e->mlx, e->win, (l->x - l->y),
				((l->y + l->x) / 2), e->colors[e->color]);
		l->i++;
	}
}

void	ligne_un(t_env *e, t_line *l)
{
	l->cumul = l->dx / 2;
	l->i = 1;
	while (l->i <= l->dx)
	{
		l->x += l->xinc;
		l->cumul += l->dy;
		if (l->cumul >= l->dx)
		{
			l->cumul -= l->dx;
			l->y += l->yinc;
		}
		mlx_pixel_put(e->mlx, e->win, (l->x - l->y),
				((l->y + l->x) / 2), e->colors[e->color]);
		l->i++;
	}
}

void	ligne(t_env *e, t_line *l, int xf, int yf)
{
	l->x = l->xi;
	l->y = l->yi;
	l->dx = xf - l->xi;
	l->dy = yf - l->yi;
	l->xinc = (l->dx > 0) ? 1 : -1;
	l->yinc = (l->dy > 0) ? 1 : -1;
	l->dx = ft_abs(l->dx);
	l->dy = ft_abs(l->dy);
	if (l->dx > l->dy)
		ligne_un(e, l);
	else
		ligne_deux(e, l);
}
