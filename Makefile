#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/01 21:27:57 by pdelobbe          #+#    #+#              #
#    Updated: 2015/05/01 21:52:55 by pdelobbe         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = arkanoid

FLG = -Wall -Wextra -Werror

SRC = main.c

OBJ = main.o

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLG) -I libft/includes/ -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L./libft/ -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all