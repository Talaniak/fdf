/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 05:40:56 by maviot            #+#    #+#             */
/*   Updated: 2016/12/04 05:44:04 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = str;
	if (n == 0)
		return (str);
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}
