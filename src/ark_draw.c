/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 23:14:01 by ybarbier          #+#    #+#             */
/*   Updated: 2015/05/02 23:14:03 by ybarbier         ###   ########.fr       */
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

void 		ark_draw_brick(GLFWwindow *window, int x, int y)
{
	glVertex2f(-0.1f + (x * 0.2f) - 1.f + 0.1f, 0.05f + (y * 0.1f) - 0.5f + 0.05f);
	glVertex2f(0.1f + (x * 0.2f) - 1.f + 0.1f, 0.05f + (y * 0.1f) - 0.5f + 0.05f);

	glVertex2f(0.1f + (x * 0.2f) - 1.f + 0.1f, -0.05f + (y * 0.1f) - 0.5f + 0.05f);
	glVertex2f(-0.1f + (x * 0.2f) - 1.f + 0.1f, -0.05f + (y * 0.1f) - 0.5f + 0.05f);
}

void		ark_draw_bricks(GLFWwindow *window, t_ark *ark)
{
	int x;
	int y;


				glColor3f(1.f, 1.f, 1.f);
				glVertex2f(-1.f, 1.f);
				glVertex2f(1.f, 1.f);
				glVertex2f(1.f, -1.f);
				glVertex2f(-1.f, -1.f);
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (ark->lvl.grid[x][y] == 1)
			{

				// glVertex2f((-1.f / 5.0) + (y * BRICK_WIDTH), (1.f / 10.0) + (x * BRICK_HEIGHT));
				// glVertex2f((1.f / 5.0) + (y * BRICK_WIDTH) + BRICK_WIDTH, (1.f / 10.0) + (x * BRICK_HEIGHT));
				// glVertex2f((-1.f / 5.0) + (x * BRICK_HEIGHT), (-1.f / 10.0) + (x * BRICK_HEIGHT));
				// glVertex2f((1.f / 5.0) + (y * BRICK_WIDTH) + BRICK_WIDTH, (-1.f / 10.0) + (x * BRICK_HEIGHT));
				//

				// ; x y
				glColor3f(1.f, 0.3f, 0.f);
				ark_draw_brick(window, x, y);

				// glVertex2f(-0.1f + (x * 0.2f) - 1.f + 0.1f, 0.05f + (y * 0.1f) - 0.5f + 0.05f);
				// glVertex2f(0.1f + (x * 0.2f) - 1.f + 0.1f, 0.05f + (y * 0.1f) - 0.5f + 0.05f);
				//
				// glVertex2f(0.1f + (x * 0.2f) - 1.f + 0.1f, -0.05f + (y * 0.1f) - 0.5f + 0.05f);
				// glVertex2f(-0.1f + (x * 0.2f) - 1.f + 0.1f, -0.05f + (y * 0.1f) - 0.5f + 0.05f);
				//
				// glVertex2f(-0.1f + 0.2f , 0.1f + 0.2f);
				// glVertex2f(0.1f + 0.2f, 0.1f + 0.2f);
				// glVertex2f(0.1f + 0.2f, -0.1f + 0.2f);
				// glVertex2f(-0.1f + 0.2f, -0.1f + 0.2f);

				//
				// ft_putendl("x:");
				// ft_putnbr(x);
				// ft_putendl("y:");
				// ft_putnbr(y);
			}
			x++;
		}
		y++;
	}
}

void		ark_draw_game(GLFWwindow *window, t_ark *ark)
{
	float	ratio;
	int		width;
	int		height;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float) height;

	glViewport((width / 2) - 200, (height / 2) - 300, 400, 600); //Game

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

	glBegin(GL_QUADS);

	ark_draw_bricks(window, ark);

	glEnd();

	ark_draw_score(window, width, height);
	ark_draw_life(window, width, height);


	glfwSwapBuffers(window);
	glfwPollEvents();
}
