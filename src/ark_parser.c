/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:41:52 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/05/03 02:21:14 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	ark_get_filenames(t_ark *ark, char *txt)
{
	int		i;

	i = 0;
	ark->levels = ft_strsplit(txt, '\n');
	ark->levels[ark->count_lvl] = NULL;
	while (i < ark->count_lvl)
	{
		ark->levels[i] = ft_strjoin("levels/", ark->levels[i]);
		++i;
	}
}

int			ark_list_levels(t_ark *ark, char *filename)
{
	int		fd;
	int		n;
	char	*str;
	char	*txt;

	ark->levels = NULL;
	ark->count_lvl = 0;
	ark->current_lvl = 0;
	if ((txt = (char *)malloc(1)) == NULL)
		return (0);
	if ((fd = open(filename, O_RDONLY)) != -1)
	{
		while ((n = ft_get_next_line(fd, &str)) == 1)
		{
			if (str[0])
			{
				if (str[0] != '\n')
				{
					txt = ft_strjoin(txt, "\n");
					txt = ft_strjoin(txt, str);
					++ark->count_lvl;
				}
			}
		}
	}
	else
		return (0);
	close(fd);
	ark_get_filenames(ark, txt);
	return (1);
}
