/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:37:33 by maviot            #+#    #+#             */
/*   Updated: 2016/12/05 19:14:17 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*tmp;

	tmp = (char *)str;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (tmp[i] == (char)c)
			return (&tmp[i]);
		i--;
	}
	if (tmp[i] == (char)c)
		return (&tmp[i]);
	else
		return (NULL);
}
