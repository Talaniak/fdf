/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:14:07 by maviot            #+#    #+#             */
/*   Updated: 2016/12/06 22:24:11 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(const char *str)
{
	int		i;
	int		j;
	int		k;

	if (!str)
		return (NULL);
	i = 0;
	while (ft_isblank(str[i]) == 1)
		i++;
	j = 0;
	k = 0;
	while (str[k] != '\0')
	{
		if (ft_isblank(str[k]) == 0)
		{
			k++;
			j = k;
		}
		else
			k++;
	}
	if (j == 0)
		return (ft_strdup(""));
	return (ft_strsub(str, i, j - i));
}
