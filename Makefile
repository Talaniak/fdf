# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maviot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 23:03:07 by maviot            #+#    #+#              #
#    Updated: 2017/09/25 10:31:01 by maviot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =	main.c \
		get_param.c \
		exit_cases.c\

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

LMX = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(addprefix $(SRCPATH), $(SRCS)) \
		-I includes/fdf.h
	@make -C libft
	@gcc $(FLAGS) $(OBJS) $(LMX) libft/libft.a libft/libmlx.a -o $(NAME)

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME)

re: fclean all

