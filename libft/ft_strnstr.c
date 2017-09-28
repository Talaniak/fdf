/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 01:47:18 by maviot            #+#    #+#             */
/*   Updated: 2016/11/30 01:59:47 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	save;

	if (!*to_find)
		return ((char *)src);
	while (n > 0 && *src != '\0')
	{
		save = n;
		if (*src == *to_find)
		{
			s1 = (char *)src;
			s2 = (char *)to_find;
			while (*s1++ == *s2++ && save > 0)
			{
				if (!*s2)
					return ((char *)src);
				save--;
			}
		}
		src++;
		n--;
	}
	return (NULL);
}
