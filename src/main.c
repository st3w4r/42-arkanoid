/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 01:25:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/03 01:21:45 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void key_callback(GLFWwindow* window, int key, int scancode, \
	int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if ((key == GLFW_KEY_LEFT && action == GLFW_PRESS) ||
		(key == GLFW_KEY_RIGHT && action == GLFW_PRESS))
		ark_player_move(window, key);
}

static void error_callback(int error, const char* description)
{
	(void)error;
	ark_error_str((char*)description);
}

static void	ark_print_levels(t_ark *ark)
{
	int		i;

	i = 0;
	ft_putendl("------------------------------");
	ft_putstr("Nombre de levels : ");
	ft_putnbr(ark->count_lvl);
	ft_putchar('\n');
	ft_putstr("Level actuel : ");
	ft_putnbr(ark->current_lvl);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putendl("Liste des levels :");
	while (i < ark->count_lvl)
	{
		ft_putendl(ark->levels[i]);
		++i;
	}
	ft_putendl("------------------------------");
}

int		main(int argc, char *argv[])
{
	t_ark		ark;
	GLFWwindow	*window;
	int			width;
	int			height;
	double		time;

	if (argc > 1)
	{
		if (ark_list_levels(&ark, argv[1]))
		{
			ark_print_levels(&ark); //tmp

			glfwSetErrorCallback(error_callback);

			if (!glfwInit())
				exit(EXIT_FAILURE);

			window = glfwCreateWindow(WIN_W, WIN_H, "Arkanoid", NULL, NULL);

			if (!window)
			{
				glfwTerminate();
				exit(EXIT_FAILURE);
			}

			glfwMakeContextCurrent(window);
			glfwSwapInterval(1);
			glfwSetKeyCallback(window, key_callback);

			while (!glfwWindowShouldClose(window) && ark.current_lvl < ark.count_lvl)
			{
				ark_load_level(&ark);
				while (!glfwWindowShouldClose(window) && ark.lvl.life > 0)
				{
					ark_draw_game(window, &ark);
					// Break : ark.lvl.life == 0
				}
				++ark.current_lvl;
			}
			glfwDestroyWindow(window);
			glfwTerminate();
		}
		else
			ft_putendl("usage : ./arkanoid map_list.ark");

	}
	exit(EXIT_SUCCESS);
}

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
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;
		glViewport(0, 0, width, height);

		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
		glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	*/
