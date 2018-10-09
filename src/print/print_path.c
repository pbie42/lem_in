/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:28:34 by pbie              #+#    #+#             */
/*   Updated: 2018/10/09 20:50:27 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		free_print_path(t_qv *path)
{
	t_qv *tmp;
	t_qv *tmp2;

	tmp = path;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}

void		print_path(t_room *end)
{
	t_qv	*path;
	t_qv	*tmp_path;
	t_room *tmp_end;
	t_room *parent;

	tmp_end = end;
	if (!end)
		return ;
	int i = 0;
	while (tmp_end->end_parent)
	{
		parent = tmp_end->end_parent;
		path = new_link(end, 0);
		path = add_to_start(path, new_link(parent, 0));
		while (parent->parent)
		{
			ft_putstr("current parent: ");
			ft_putendl(parent->name);
			ft_putstr("parents parent: ");
			ft_putendl(parent->parent->name);
			path = add_to_start(path, new_link(parent->parent, 0));
			parent = parent->parent;
		}
		ft_putstr(path->room->name);
		tmp_path = path;
		while (tmp_path->next)
		{
			ft_putstr(" -> ");
			ft_putstr(tmp_path->next->room->name);
			tmp_path = tmp_path->next;
		}
		ft_putchar('\n');
		free_print_path(path);
		tmp_end = tmp_end->end_parent;
	}
}
