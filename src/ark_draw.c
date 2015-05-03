/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 23:14:01 by ybarbier          #+#    #+#             */
/*   Updated: 2015/05/03 23:04:08 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		window_size_callback(GLFWwindow *window, int width, int height)
{
	if (width <= WIN_W_MIN || height <= WIN_H_MIN)
	{
		width = (width <= WIN_W_MIN) ? WIN_W_MIN : width;
		height = (height <= WIN_H_MIN) ? WIN_H_MIN : height;
		glfwSetWindowSize(window, width, height);
	}
}

void		ark_draw_score(GLFWwindow *window, int width, int height)
{
	glViewport(0, height - 50, width, 50);
	glBegin(GL_QUADS);
	glColor3f(0.f, 0.3f, 9.f);
	glVertex2f(-1.f, -1.f);
	glVertex2f(1.f, -1.f);
	glVertex2f(1.f, 1.f);
	glVertex2f(-1.f, 1.f);
	glEnd();
}

void		ark_draw_life(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, 50);
	glBegin(GL_QUADS);
	glColor3f(0.f, 0.7f, 3.f);
	glVertex2f(-1.f, -1.f);
	glVertex2f(1.f, -1.f);
	glVertex2f(1.f, 1.f);
	glVertex2f(-1.f, 1.f);
	glEnd();
}

void		ark_draw_bricks(t_lvl *lvl)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 10)
	{
		while (x < 10)
		{
			if (lvl->grid[x][y])
			{
				ark_draw_brick(40 * x, 20 * y + 200, lvl->grid[x][y]);
			}
			++x;
		}
		x = 0;
		++y;
	}
}

void		ark_draw_game(GLFWwindow *window, t_ark *ark)
{
	float	ratio;
	int		width;
	int		height;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float) height;
	glViewport((width / 2) - 200, (height / 2) - 300, 400, 600);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	ark_draw_bricks(&ark->lvl);
	ark_draw_player(g_ark->lvl.player.x, 560);
	ark_draw_ball(5, 5);
	ark_draw_score(window, width, height);
	ark_draw_life(window, width, height);
	glfwSwapBuffers(window);
	glfwPollEvents();
}
