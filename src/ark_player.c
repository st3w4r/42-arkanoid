/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:29:31 by ybarbier          #+#    #+#             */
/*   Updated: 2015/05/03 23:37:37 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		ark_player_move(int key)
{
	if (key == GLFW_KEY_LEFT &&
		g_ark->lvl.player.x > 0)
		g_ark->lvl.player.x -= 10;
	if (key == GLFW_KEY_RIGHT &&
		g_ark->lvl.player.x < 320)
		g_ark->lvl.player.x += 10;
}
