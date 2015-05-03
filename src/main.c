/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 01:25:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/03 23:06:07 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void			ark_print_levels(t_ark *ark)
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

static GLFWwindow	*ark_create_window(void)
{
	GLFWwindow	*window;

	window = glfwCreateWindow(WIN_W, WIN_H, "Arkanoid", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
	return (window);
}

static void			ark_loop(GLFWwindow *window, t_ark *ark)
{
	while (!glfwWindowShouldClose(window) && ark->current_lvl < ark->count_lvl)
	{
		ark_load_level(ark);
		ark->lvl.player.x = 0.f;
		ark->lvl.player.y = 0.f;
		ark->lvl.player.width = 0.6f;
		ark->lvl.player.height = 0.05f;
		while (!glfwWindowShouldClose(window) && ark->lvl.life > 0)
		{
			ark_draw_game(window, ark);
			glfwPollEvents();
		}
		ark->current_lvl += 1;
	}
}

int					main(int argc, char **argv)
{
	t_ark		ark;
	GLFWwindow	*window;

	if (argc > 1)
	{
		if (ark_list_levels(&ark, argv[1]))
		{
			ark_print_levels(&ark);
			glfwSetErrorCallback(error_callback);
			if (!glfwInit())
				exit(EXIT_FAILURE);
			if (!(window = ark_create_window()))
				exit(EXIT_FAILURE);
			g_ark = &ark;
			ark_loop(window, &ark);
			glfwDestroyWindow(window);
			glfwTerminate();
		}
		else
			ft_putendl("usage : ./arkanoid map_list.ark");
	}
	exit(EXIT_SUCCESS);
}
