/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 01:46:52 by maviot            #+#    #+#             */
/*   Updated: 2016/11/30 01:47:08 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	char	*s1;
	char	*s2;

	if (!*to_find)
		return ((char *)src);
	while (*src != '\0')
	{
		if (*src == *to_find)
		{
			s1 = (char *)src;
			s2 = (char *)to_find;
			while (*s1++ == *s2++)
			{
				if (*s2 == '\0')
					return ((char *)src);
			}
		}
		src++;
	}
	return (NULL);
}
