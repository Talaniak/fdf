/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 01:45:36 by maviot            #+#    #+#             */
/*   Updated: 2016/12/07 06:08:00 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	while (dest[i] && i < n)
		i++;
	dest_len = i;
	if (i == n)
		return (i + ft_strlen(src));
	while (src[i - dest_len] != '\0' && i < n - 1)
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	if (dest_len < n)
		dest[i] = '\0';
	src_len = ft_strlen(src);
	return (dest_len + src_len);
}
