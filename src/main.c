/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 01:25:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/02 22:02:10 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arkanoid.h"

static void	ark_print_maps(t_ark *ark)
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

static void	ark_play_lvl(t_ark *ark)
{
	t_lvl lvl;

	if (ark_init_level(ark, &lvl))
	{
		ft_putstr("Level \"");
		ft_putstr(ark->levels[ark->current_lvl]);
		ft_putendl("\" OK.");
	}
}

int			main(int argc, char *argv[])
{
	t_ark	ark;

	if (argc > 1)
	{
		if (ark_list_levels(&ark, argv[1]))
		{
			ark_print_maps(&ark);
			while (ark.current_lvl < ark.count_lvl)
			{
				ark_play_lvl(&ark);
				++ark.current_lvl;
			}
		}
	}
	else
		ft_putendl("usage : ./arkanoid map_list.ark");
	return (0);
}
