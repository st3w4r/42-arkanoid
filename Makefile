#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/01 21:27:57 by pdelobbe          #+#    #+#              #
#    Updated: 2015/05/02 16:51:48 by ybarbier         ###   ########.fr        #
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

.PHONY: clean fclean re libft_build glfw_build

all: libft_build glfw_build $(NAME)

$(NAME): $(OBJ)
	git submodule init
	git submodule update
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

#glfw:
#	git submodule init ;\
#	git submodule update ;\
#	cd glfw/ ;\
#	cmake . ; \
#	cd ..

libft_build:
	make -C libft/

glfw_build:
	make -C glfw/

clean:
	make -C libft/ clean
	make -C glfw/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
