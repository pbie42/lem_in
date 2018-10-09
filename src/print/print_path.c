/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:28:34 by pbie              #+#    #+#             */
/*   Updated: 2018/10/09 22:03:50 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		print_path(t_qv *path)
{
	t_qv *tmp_path;

	ft_putstr(path->room->name);
	tmp_path = path;
	while (tmp_path->next)
	{
		ft_putstr(" -> ");
		ft_putstr(tmp_path->next->room->name);
		tmp_path = tmp_path->next;
	}
	ft_putchar('\n');
}
