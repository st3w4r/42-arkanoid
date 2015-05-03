/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 20:18:50 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/02 20:48:26 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <GLFW/glfw3.h>
# include "libft.h"

# define WIN_W 400
# define WIN_W_MIN 400
# define WIN_H 500
# define WIN_H_MIN 500

# define BRICK_WIDTH 40
# define BRICK_HEIGHT 20

# define BALL_DIAM 10

typedef struct	s_ball
{
	int			x;
	int			y;
	int			diam;
}				t_ball;

typedef struct	s_player
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_player;

typedef struct	s_lvl
{
	int			grid[10][10];
	int			life;
	t_player	player;
	t_ball		ball;
}				t_lvl;

typedef struct	s_ark
{
	char		**levels;
	int			count_lvl;
	int			current_lvl;
	t_lvl		lvl;
}				t_ark;

int		ark_list_levels(t_ark *ark, char *filename);
int		ark_init_level(t_ark *ark, t_lvl *lvl);

/*
** Name: ark_error
** File: ark_error.c
** Desc: Gestion error
*/
void	ark_exit(void);
void	ark_malloc_error(void);
void	ark_error_str(char *str);
void	ark_error_str_exit(char *str);

/*
** Name: ark_draw
** File: ark_draw.c
** Desc: Display Window
*/
void		window_size_callback(GLFWwindow *window, int width, int height);
void		ark_draw_game(GLFWwindow *window, t_ark *ark);


#endif
