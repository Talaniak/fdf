/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:44:44 by maviot            #+#    #+#             */
/*   Updated: 2016/12/07 10:24:55 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_range(int min, int max)
{
	int		i;
	int		*tab;
	int		diff;

	if (min >= max)
		return (NULL);
	diff = (max - min);
	tab = (int*)malloc(sizeof(int) * diff + 1);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	tab[i] = 0;
	return (tab);
}
