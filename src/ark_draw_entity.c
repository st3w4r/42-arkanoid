/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_draw_entity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 18:30:50 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/03 23:03:16 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		ark_draw_ball(float x, float y)
{
	glBegin(GL_QUADS);
	glColor3f(0.3f, 0.8f, 0.8f);
	glVertex2f(((x / 200) -1), -((y / 300) - 1));
	glVertex2f((((x / 200) - 1) + 0.05), -((y / 300) - 1));
	glVertex2f((((x / 200) -1) + 0.05), -((y / 300) - 1) - 0.0333);
	glVertex2f(((x / 200) - 1), -((y / 300) - 1) - 0.0333);
	glEnd();
}

void		ark_draw_player(float x, float y)
{
	glBegin(GL_QUADS);
	glColor3f(0.3f, 0.3f, 0.8f);
	glVertex2f(((x / 200) -1), -((y / 300) - 1));
	glVertex2f((((x / 200) - 1) + PW), -((y / 300) - 1));
	glVertex2f((((x / 200) -1) + PW), -((y / 300) - 1) - PH);
	glVertex2f(((x / 200) - 1), -((y / 300) - 1) - PH);
	glEnd();
}

void		ark_draw_brick(float x, float y, int hits)
{
	glBegin(GL_QUADS);
	if (hits == 1)
		glColor3f(0.8f, 0.3f, 0.3f);
	if (hits == 2)
		glColor3f(0.8f, 0.3f, 0.3f);
	if (hits == 3)
		glColor3f(0.8f, 0.3f, 0.3f);
	if (hits == 4)
		glColor3f(0.8f, 0.3f, 0.3f);
	if (hits == 5)
		glColor3f(0.8f, 0.3f, 0.3f);
	else
		glColor3f(0.8f, 0.3f, 0.3f);
	glVertex2f(((x / 200) -1), -((y / 300) - 1));
	glVertex2f((((x / 200) - 1) + BW), -((y / 300) - 1));
	glVertex2f((((x / 200) -1) + BW), -((y / 300) - 1) - BH);
	glVertex2f(((x / 200) - 1), -((y / 300) - 1) - BH);
	glEnd();
}
