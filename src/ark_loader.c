/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 23:10:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/02 23:51:47 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int			ark_load_level(t_ark *ark)
{
	int		fd;
	int		n;
	char	*str;

	if ((fd = open(ark->levels[ark->current_lvl], O_RDONLY)) != -1)
	{
		while ((n = ft_get_next_line(fd, &str)) == 1)
		{
			ft_putendl(str);
		}
	}
	ark->lvl.life = 3;
	return (1);
}
