# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maviot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 23:03:07 by maviot            #+#    #+#              #
#    Updated: 2017/09/29 09:41:23 by maviot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =	main.c \
		e_init.c \
		parser.c \
		exit_cases.c\
		inputs.c\

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror -fsanitize=address
LMX = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(addprefix $(SRCPATH), $(SRCS)) 
	@gcc $(FLAGS) -c $(addprefix $(SRCPATH), $(SRCS)) \
		-I includes/fdf.h
	@make -C libft
	gcc $(FLAGS) $(OBJS) $(LMX) libft/libft.a libft/libmlx.a -o $(NAME)

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME)

re: fclean all

