/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 07:47:56 by maviot            #+#    #+#             */
/*   Updated: 2016/12/07 00:14:55 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	char	*map;
	int		i;

	if (!str || !f)
		return (NULL);
	map = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		map[i] = f(str[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
