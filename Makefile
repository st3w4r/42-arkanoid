#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/01 21:27:57 by pdelobbe          #+#    #+#              #
#    Updated: 2015/05/03 21:56:23 by pdelobbe         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = arkanoid
PATH_SRC = ./src/

CC = cc
CFLAGS = -I ./libft/includes/ -I ./glfw/include/ -Wall -Wextra -Werror
LIBS = -L ./libft/ -lft -L ./glfw/src/ -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

SRC =	main.c \
		ark_parser.c  \
		ark_init.c \
		ark_loader.c \
		ark_error.c \
		ark_draw_entity.c \
		ark_draw.c \
		ark_player.c \
		ark_callback.c

OBJ = $(addprefix $(PATH_SRC), $(SRC:.c=.o))


.PHONY: clean fclean re glfw libft_build glfw_build

all: glfw libft_build glfw_build $(NAME)

$(NAME): $(OBJ)
	@cd glfw/ ;\
	cmake . ;
	@make -C glfw/
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

glfw:
	@git submodule init ;\
	git submodule update ;\
	#cd glfw/ ;\
	#cmake . ; \

libft_build:
	@make -C libft/

#glfw_build:
#	make -C glfw/

clean:
	make -C libft/ clean
	make -C glfw/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
