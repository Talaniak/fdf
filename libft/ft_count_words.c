/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:44:32 by maviot            #+#    #+#             */
/*   Updated: 2017/10/04 02:50:15 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(char const *str, char c)
{
	int			i;
	int			words;
	int			flag;

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
