/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 23:10:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/03 04:57:10 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	ark_complete_grid(t_lvl *lvl, int j)
{
	int		i;

	i = 0;
	while (j < 10)
	{
		while (i < 10)
		{
			lvl->grid[i][j] = 0;
			++i;
		}
		i = 0;
		++j;
	}
}

static void	ark_fill_line(t_lvl *lvl, int index, int i, char c)
{
	if (ft_isdigit(c))
	{
		c = (c - 48);
		if (c > 5)
			c = 5;
		lvl->grid[i][index] = c;
		if (c > 0 && c < 5)
			lvl->life += c;
	}
	else
		lvl->grid[i][index] = 0;
}

static void	ark_read_line(t_lvl *lvl, char *str, int index)
{
	int		i;

	i = 0;
	while (str[i] && i < 10)
	{
		ark_fill_line(lvl, index, i, str[i]);
		++i;
	}
	while (i < 10)
	{
		lvl->grid[i][index] = 0;
		++i;
	}
}

static void	ark_print_grid(t_ark *ark)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 10)
	{
		while (i < 10)
		{
			ft_putnbr(ark->lvl.grid[i][j]);
			ft_putchar(' ');
			++i;
		}
		ft_putchar('\n');
		i = 0;
		++j;
	}
}

int			ark_load_level(t_ark *ark)
{
	int		fd;
	int		n;
	char	*str;
	int		i;

	i = 0;
	ark->lvl.life = 0;
	str = NULL;
	if ((fd = open(ark->levels[ark->current_lvl], O_RDONLY)) != -1)
	{
		while (((n = ft_get_next_line(fd, &str)) == 1) && (i < 10))
		{
			if (str[0] && str[0] != '\n')
			{
				ark_read_line(&(ark->lvl), str, i);
				++i;
			}
		}
	}
	close(fd);
	ark_complete_grid(&ark->lvl, i);
	ark_print_grid(ark);
	return (1);
}
