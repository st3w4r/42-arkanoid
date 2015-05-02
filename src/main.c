/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:40:33 by ybarbier          #+#    #+#             */
/*   Updated: 2015/05/02 16:23:55 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void key_callback(GLFWwindow* window, int key, int scancode, \
	int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

static void error_callback(int error, const char* description)
{
	(void)error;
	ark_error_str((char*)description);
}

int main(void)
{
	GLFWwindow	*window;
	int			width;
	int			height;
	double		time;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(500, 500, "Arkanoid", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	while (!glfwWindowShouldClose(window))
	{
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		time = glfwGetTime();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);


/*

	GLFWwindow* window;
	window = glfwCreateWindow(640, 480, "Arkanoid", NULL, NULL);

	while (!glfwWindowShouldClose(window))
	{

	}
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(640, 480, "Arkanoid", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	while (!glfwWindowShouldClose(window))
	{
		// float ratio;
		// int width, height;
		// glfwGetFramebufferSize(window, &width, &height);
		// ratio = width / (float) height;
		// glViewport(0, 0, width, height);
		// glClear(GL_COLOR_BUFFER_BIT);
		// glMatrixMode(GL_PROJECTION);
		// glLoadIdentity();
		// glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		// glMatrixMode(GL_MODELVIEW);
		// glLoadIdentity();
		// glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
		// glBegin(GL_TRIANGLES);
		// glColor3f(1.f, 0.f, 0.f);
		// glVertex3f(-0.6f, -0.4f, 0.f);
		// glColor3f(0.f, 1.f, 0.f);
		// glVertex3f(0.6f, -0.4f, 0.f);
		// glColor3f(0.f, 0.f, 1.f);
		// glVertex3f(0.f, 0.6f, 0.f);
		// glEnd();
		// glfwSwapBuffers(window);
		// glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	*/
}
