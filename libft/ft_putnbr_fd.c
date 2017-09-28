/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 06:57:54 by maviot            #+#    #+#             */
/*   Updated: 2016/12/05 07:16:22 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_unsigned_putnbr_fd(n / 10, fd);
		ft_unsigned_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = (n * -1);
	}
	ft_unsigned_putnbr_fd(n, fd);
}
