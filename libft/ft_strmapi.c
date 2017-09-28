/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 08:19:59 by maviot            #+#    #+#             */
/*   Updated: 2016/12/07 00:17:41 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	if (!str || !f)
		return (NULL);
	map = ft_strnew(ft_strlen(str));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		map[i] = f(i, str[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
