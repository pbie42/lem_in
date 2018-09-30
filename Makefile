# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 13:45:50 by pbie              #+#    #+#              #
#    Updated: 2018/09/30 14:56:46 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -g -I includes

SRC = main.c \
		src/hash_table/ht_free.c \
		src/hash_table/ht_hash.c \
		src/hash_table/ht_new.c \
		src/hash_table/ht_resize.c \
		src/utils/errors.c \
		src/utils/ft_floor.c \
		src/utils/ft_prime.c \
		src/utils/ft_sqroot.c \
		src/utils/ft_pow.c


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
