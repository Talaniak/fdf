/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:48:01 by maviot            #+#    #+#             */
/*   Updated: 2016/12/05 17:54:46 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	unsigned_c;
	int				i;

	unsigned_c = (unsigned char)c;
	ptr = (unsigned char *)s;
	i = 0;
	while (n > 0 && ptr[i] != unsigned_c)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (NULL);
	return (&ptr[i]);
}
