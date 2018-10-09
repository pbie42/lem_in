/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:28:34 by pbie              #+#    #+#             */
/*   Updated: 2018/10/09 17:00:07 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		print_path(t_room *end)
{
	t_qv	*path;
	t_room *tmp;

	tmp = end;
	if (!end)
		return ;
	path = new_link(end, 0);
	int i = 0;
	while (tmp->parent)
	{
		path = add_to_start(path, new_link(tmp->parent, 0));
		tmp = tmp->parent;
	}
	ft_putstr(path->room->name);
	while (path->next)
	{
		ft_putstr(" -> ");
		ft_putstr(path->next->room->name);
		path = path->next;
	}
	ft_putchar('\n');
}
