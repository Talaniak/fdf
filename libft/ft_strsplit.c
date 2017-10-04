/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <maviot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:25:04 by maviot            #+#    #+#             */
/*   Updated: 2017/10/04 02:59:45 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
