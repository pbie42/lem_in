# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 13:45:50 by pbie              #+#    #+#              #
#    Updated: 2018/10/05 16:22:10 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -g -I includes

SRC = main.c \
		src/hash_table/ht_free.c \
		src/hash_table/ht_hash.c \
		src/hash_table/ht_new.c \
		src/hash_table/ht_resize.c \
		src/parser/ants.c \
		src/parser/commands.c \
		src/parser/comments.c \
		src/parser/links.c \
		src/parser/parse.c \
		src/parser/rooms.c \
		src/print/print_links.c \
		src/utils/errors.c \
		src/utils/ft_floor.c \
		src/utils/ft_free_matrix.c \
		src/utils/ft_is_num.c \
		src/utils/ft_only_white.c \
		src/utils/ft_pow.c \
		src/utils/ft_prime.c \
		src/utils/ft_sqroot.c \
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
