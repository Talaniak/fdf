/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 22:36:15 by maviot            #+#    #+#             */
/*   Updated: 2016/12/07 07:20:45 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					ft_char_nb(unsigned int n)
{
	int				i;

	i = 1;
	if (n == 0)
		return (1);
	else
	{
		while (n > 0)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

static unsigned int			ft_abs(int n)
{
	unsigned int	nb;

	nb = 0;
	if (n < 0)
		nb = -n;
	if (n >= 0)
		nb = n;
	return (nb);
}

char						*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;

	i = 0;
	nb = ft_abs(n);
	str = ft_strnew(ft_char_nb(nb));
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[i++] = nb + '0';
	while (nb > 0)
	{
		str[i++] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
