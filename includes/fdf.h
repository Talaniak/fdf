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

typedef struct		s_param
{
	void			*mlx;
	void			*win;
	int				curkey;
	int				map_x;
	int				map_y;
	int				data_map[1000][1000];
	int				l_r;
	int				u_d;
}					t_param;

/*
 * * get_param.c
 */

void	get_x_y(t_param *param, char **av);
int		get_x(char *str);
void	get_z(t_param *param, char **av);

/*
 * * exit_cases.c
 */

void	my_exit(int ac);
void	map_err(void);

#endif
