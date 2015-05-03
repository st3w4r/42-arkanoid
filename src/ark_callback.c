/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:57:50 by ybarbier          #+#    #+#             */
/*   Updated: 2015/05/03 21:57:51 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	key_callback(GLFWwindow *window, int key, int scancode, \
	int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if ((key == GLFW_KEY_LEFT &&
		(action == GLFW_PRESS || (action == GLFW_REPEAT))) ||
		(key == GLFW_KEY_RIGHT &&
		(action == GLFW_PRESS || (action == GLFW_REPEAT))))
		ark_player_move(window, key);
}

void	error_callback(int error, const char *description)
{
	(void)error;
	ark_error_str((char*)description);
}

void	window_size_callback(GLFWwindow *window, int width, int height)
{
	if (width <= WIN_W_MIN || height <= WIN_H_MIN)
	{
		width = (width <= WIN_W_MIN) ? WIN_W_MIN : width;
		height = (height <= WIN_H_MIN) ? WIN_H_MIN : height;
		glfwSetWindowSize(window, width, height);
	}
}
