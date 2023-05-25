# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 12:44:58 by malhamel          #+#    #+#              #
#    Updated: 2023/05/08 14:07:53 by malhamel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3 -w
RM		=	rm	-rf

SRCS 	=	so_long.c\
			map.c\
			parse.c\
			exit.c\
			input_handling.c\
			render.c\
			game_utils.c\
			path_validation.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c

all: $(NAME)

$(NAME): $(SRCS)
	$(MAKE) all -C mlx
	$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx

re: fclean $(NAME)

.PHONY = all clean fclean re