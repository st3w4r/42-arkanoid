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

# include "libft/includes/libft.h"

# define WIN_WIDTH 400
# define WIN_WIDTH_MIN 400
# define WIN_HEIGHT 400
# define WIN_HEIGHT_MIN 400

# define BRICK_WIDTH 40
# define BRICK_HEIGHT 20

# define BALL_DIAM 10

typedef struct	s_lvl
{
	int			grid[10][5];
	int			htis;
	int			life;
}				t_lvl;

typedef struct	s_ark
{
	char		**levels;
	int			count_lvl;
	int			current_lvl;
}				t_ark;

int		ark_list_levels(t_ark *ark, char *filename);
int		ark_init_level(t_ark *ark, t_lvl *lvl);

#endif
