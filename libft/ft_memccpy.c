/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:23:49 by maviot            #+#    #+#             */
/*   Updated: 2016/12/05 09:24:31 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dptr;
	unsigned char	*sptr;

	i = -1;
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	while (++i < n)
	{
		dptr[i] = sptr[i];
		if (sptr[i] == (unsigned char)c)
			return (&dest[i + 1]);
	}
	return (NULL);
}
