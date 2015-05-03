/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:29:31 by ybarbier          #+#    #+#             */
/*   Updated: 2015/05/03 04:29:32 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		ark_player_move(GLFWwindow *window, int key)
{
	if (key == GLFW_KEY_LEFT &&
		g_ark->lvl.player.x > (-1 + (g_ark->lvl.player.width / 2)))
		g_ark->lvl.player.x -= 0.05;
	if (key == GLFW_KEY_RIGHT &&
		g_ark->lvl.player.x < (1 - (g_ark->lvl.player.width / 2)))
		g_ark->lvl.player.x += 0.05;
}
