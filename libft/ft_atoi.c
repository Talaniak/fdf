/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <maviot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:59:19 by maviot            #+#    #+#             */
/*   Updated: 2017/10/04 01:31:34 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_spaces(const char *str, int i)
{
	if ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	int i;
	int nbr;
	int neg;

	nbr = 0;
	neg = 0;
	i = 0;
	while (ft_check_spaces(nptr, i) == 1)
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] != '\0' && (nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		nbr = nbr * 10;
		nbr = nbr + (int)nptr[i] - '0';
		i++;
	}
	if (neg == 1)
		return (nbr * -1);
	else
		return (nbr);
}
