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
	if (width <= 400 || height <= 500)
	{
		width = (width <= 400) ? 400 : width;
		height = (height <= 500) ? 500 : height;
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

void		ark_draw_game(GLFWwindow *window)
{
	float	ratio;
	int		width;
	int		height;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float) height;

	glViewport((width / 2) - 200, (height / 2) - 200, 400, 400); //Game

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

	glBegin(GL_QUADS);
	glColor3f(1.f, 0.3f, 0.f);

	glVertex2f(-1.f, -1.f);
	glVertex2f(1.f, -1.f);
	glVertex2f(1.f, 1.f);
	glVertex2f(-1.f, 1.f);
	// glColor3f(1.f, 0.f, 0.f);
	// glVertex3f(-0.6f, -0.4f, 0.f);
	// glColor3f(0.f, 1.f, 0.f);
	// glVertex3f(0.6f, -0.4f, 0.f);
	// glColor3f(0.f, 0.f, 1.f);
	// glVertex3f(0.f, 0.6f, 0.f);
	glEnd();

	ark_draw_score(window, width, height);
	ark_draw_life(window, width, height);

	glfwSwapBuffers(window);
	glfwPollEvents();
}
