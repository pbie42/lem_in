# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paul <paul@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 13:45:50 by pbie              #+#    #+#              #
#    Updated: 2018/10/30 21:38:30 by paul             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -g -I includes

SRC = main.c \
		src/bfs/list/add_to_end.c \
		src/bfs/list/add_to_start.c \
		src/bfs/list/list_length.c \
		src/bfs/list/new_link.c \
		src/bfs/bfs.c \
		src/bfs/queue.c \
		src/parser/ants.c \
		src/parser/commands.c \
		src/parser/comments.c \
		src/parser/links.c \
		src/parser/parse.c \
		src/parser/rooms.c \
		src/paths/construct_paths.c \
		src/print/print_links.c \
		src/print/print_move.c \
		src/print/print_path.c \
		src/traversal/movement/move_ants.c \
		src/traversal/movement/move_handlers.c \
		src/traversal/movement/moved.c \
		src/traversal/traversal.c \
		src/utils/errors.c \
		src/utils/ft_free_matrix.c \
		src/utils/list/l_add_end.c \
		src/utils/list/l_free.c \
		src/utils/list/l_new.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -I libft/includes/libftprintf.h libft/libftprintf.a -ltermcap
	@echo "$(NAME) created"

clean :
	make -C libft clean
	rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean : clean
	rm -rf $(NAME)
	rm -rf libft/libftprintf.a
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
