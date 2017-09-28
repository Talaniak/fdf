/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 23:23:02 by maviot            #+#    #+#             */
/*   Updated: 2017/09/25 14:34:31 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_count_words(char const *str, char c)
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

void			get_z(t_param *param, char **av)
{
	int			fd;
	char		*str;
	char		**char_map;
	int			i;
	int			j;

	char_map = NULL;
	fd = open(av[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
		char_map = ft_strsplit(str, ' ');
		j = 0;
		while (j < ft_count_words(str, ' '))
		{
			param->data_map[i][j] = atoi(char_map[j]);
			printf("%d ", param->data_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int				get_x(char *str)
{
	int			i;
	int			x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			x++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}
	return (x);
}

void			get_x_y(t_param *param, char **av)
{
	int			fd;
	char		*str;
	int			i;
	int			j;

	fd = open(av[1], O_RDONLY);
	i = 0;
	param->map_x = 0;
	while (get_next_line(fd, &str) == 1)
	{
		j = 0;
		while (str[j])
		{
			if ((str[j] < 48 || str[j] > 57) && (str[j] != 32 && str[j] != '-'))
				map_err();
			j++;
		}
		i++;
		if (param->map_x == 0)
			param->map_x = get_x(str);
	}
	param->map_y = i;
}
