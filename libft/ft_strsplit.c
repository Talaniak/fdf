/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <maviot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:25:04 by maviot            #+#    #+#             */
/*   Updated: 2017/09/25 12:31:57 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_words(char const *str, char c)
{
	int		i;
	int		words;
	int		flag;

	if (!str)
		return (0);
	i = 0;
	words = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (flag == 0 && str[i] != c)
		{
			flag = 1;
			words++;
		}
		if (flag == 1 && str[i] == c)
			flag = 0;
		i++;
	}
	return (words);
}

static int	ft_word_len(char const *s, char c)
{
	int		n;
	int		i;

	if (!s)
		return (0);
	n = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(*tab) * (words + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (words-- > 0)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		tab[i] = ft_strsub(s, j, ft_word_len(s + j, c));
		if (tab[i] == NULL)
			return (NULL);
		j = j + ft_word_len(s + j, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
