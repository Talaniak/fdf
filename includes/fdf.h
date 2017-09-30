#ifndef FDF_H
# define FDF_H

#include "../libft/get_next_line.h"
#include "../libft/libft.h"
#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

#define MAX_X 800
#define MAX_Y 600
#define DIST (MAX_X / 15)

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				curkey;
	int				zoom;
	int				max_x;
	int				max_y;
	int				map_x;
	int				map_y;
	int				x;
	int				y;
	int				z;
	int				lxa;
	int				lxb;
	int				lya;
	int				lyb;
	int				**data_map;
	int				l_r;
	int				u_d;
}					t_env;

typedef struct		s_line
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_line;


/*
 * * parser.c
 */

void	parser(t_env *e, char **av);
void	get_x_y(t_env *e, char **av);
int		get_x(char *str);
void	get_z(t_env *e, char **av);

/*
 * * exit_cases.c
 */

void	my_exit(int ac);
void	map_err(void);

/*
 * * e_init.c
 */

t_env	*e_init();
void	set_zoom(t_env *e);

/*
 * * inputs.c
 */

int		check_input(int keycode, t_env *e);

/*
 * * main.c
 */

void	draw_top_down(t_env *e);

#endif
