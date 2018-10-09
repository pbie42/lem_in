/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:28:34 by pbie              #+#    #+#             */
/*   Updated: 2018/10/09 17:57:31 by pbie             ###   ########.fr       */
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
	tmp_path = path;
	while (tmp_path->next)
	{
		ft_putstr(" -> ");
		ft_putstr(tmp_path->next->room->name);
		tmp_path = tmp_path->next;
	}
	ft_putchar('\n');
	free_print_path(path);
}
