/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 23:23:02 by maviot            #+#    #+#             */
/*   Updated: 2017/10/04 02:49:44 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			get_z(t_env *e, char **av)
{
	int			fd;
	char		*s;
	char		**char_map;
	int			i;
	int			j;

	i = 0;
	e->data_map = (int **)ft_memalloc(sizeof(int *) * e->map_y);
	while (i < e->map_y)
		e->data_map[i++] = (int *)ft_memalloc(sizeof(int) * e->map_x);
	char_map = NULL;
	if (!(fd = open(av[1], O_RDONLY)))
		ft_error("error\n");
	i = 0;
	while (get_next_line(fd, &s) == 1)
	{
		char_map = ft_strsplit(s, ' ');
		j = 0;
		while (j < ft_count_words(s, ' '))
		{
			e->data_map[i][j] = atoi(char_map[j]);
			j++;
		}
		i++;
	}
}

int				get_x(char *s)
{
	int			i;
	int			x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else
		{
			x++;
			while (s[i] != ' ' && s[i] != '\0')
				i++;
		}
	}
	return (x);
}

void			get_x_y(t_env *e, char **av)
{
	int			fd;
	char		*s;
	int			i;
	int			j;

	if (!(fd = open(av[1], O_RDONLY)))
		ft_error("error\n");
	i = 0;
	while (get_next_line(fd, &s) == 1)
	{
		j = 0;
		while (s[j])
		{
			if ((s[j] < 48 || s[j] > 57) && (s[j] != 32 && s[j] != '-'))
				map_err();
			j++;
		}
		i++;
		if (e->map_x == 0)
			e->map_x = get_x(s);
	}
	e->map_y = i;
}

void			parser(t_env *e, char **av)
{
	get_x_y(e, av);
	get_z(e, av);
	set_zoom(e);
}
