#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/01 21:27:57 by pdelobbe          #+#    #+#              #
#    Updated: 2015/05/01 22:54:36 by ybarbier         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = arkanoid
PATH_SRC = ./src/
PATH_INC = ./libft/includes/

CC = cc
# -Wall -Wextra -Werror
CFLAGS = -I $(PATH_INC) -I ./glfw/include/
LIBS = -L ./glfw/src/ -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

SRC = main.c

OBJ = $(addprefix $(PATH_SRC), $(SRC:.c=.o))

all: $(NAME) glfw

$(NAME): $(OBJ) glfw
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

glfw: lib
	git submodule init
	git submodule update
	cmake

lib:
	make -C libft/
	make -C glfw/

.PHONY: clean fclean

clean:
	make -C libft/ clean
	make -C glfw/ clean
	/bin/rm -f $(OBJ)

fclean:	clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
