/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:49:55 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/28 18:49:56 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ark_exit(void)
{
	exit(1);
}

void	ark_malloc_error(void)
{
	ft_putstr_fd("malloc error\n", 2);
	ark_exit();
}

void	ark_error_str(char *str)
{
	ft_putstr_fd(str, 2);
}

void	ark_error_str_exit(char *str)
{
	ft_putstr_fd(str, 2);
	ark_exit();
}
