/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 04:37:31 by maviot            #+#    #+#             */
/*   Updated: 2017/10/04 05:44:19 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define XS 1000
# define YS 400

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				curkey;
	int				zoom;
	int				x_start;
	int				y_start;
	int				max_x;
	int				max_y;
	int				map_x;
	int				map_y;
	int				x;
	int				y;
	int				z;
	int				x_pix;
	int				y_pix;
	int				**data_map;
	int				l_r;
	int				u_d;
	int				*colors;
	int				color;
}					t_env;

typedef struct		s_line
{
	int				xi;
	int				yi;
	int				xf;
	int				yf;
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_line;

/*
**  e_init.c
*/

t_env				*e_init(void);
void				set_colors(t_env *e);
t_line				*l_init(void);
void				set_zoom(t_env *e);

/*
**  parser.c
*/

void				parser(t_env *e, char **av);
void				get_x_y(t_env *e, char **av);
int					get_x(char *str);
void				get_z(t_env *e, char **av);

/*
**  exit_cases.c
*/

void				my_exit(int ac);
void				map_err(void);
void				ft_error(char *str);

/*
**  inputs.c
*/

int					check_input(int keycode, t_env *e);
void				p_m(t_env *e);
void				l_r(t_env *e);
void				u_d(t_env *e);
int					ft_exit(t_env *e);

/*
**  draw.c
*/

void				draw(t_env *e);
void				line_r(t_env *e, int x, int y);
void				line_d(t_env *e, int x, int y);
void				data_to_pix(t_env *e, int x, int y);

/*
**  bresenham.c
*/

void				ligne(t_env *e, t_line *l, int xf, int yf);
void				ligne_un(t_env *e, t_line *l);
void				ligne_deux(t_env *e, t_line *l);

#endif
