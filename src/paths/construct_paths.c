/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 21:59:23 by pbie              #+#    #+#             */
/*   Updated: 2018/10/16 21:04:47 by pbie             ###   ########.fr       */
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

t_paths *new_path(t_qv *path)
{
	t_paths	*tmp;

	tmp = (t_paths *)malloc(sizeof(t_paths));
	tmp->next = NULL;
	tmp->path = path;
	return tmp;
}

t_paths *add_path(t_data *data, t_qv *path)
{
	t_paths *tmp;
	if (!data->paths)
		data->paths = new_path(path);
	else
	{
		tmp = data->paths;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_path(path);
	}
	return (data->paths);
}

void		construct_paths(t_room *end, t_data *data)
{
	t_qv	*path;
	t_paths	*tmp_paths;
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
		add_to_end(path, new_link(parent, 0));
		while (parent->parent)
		{
			add_to_end(path, new_link(parent->parent, 0));
			parent = parent->parent;
		}
		data->paths = add_path(data, path);
		// free_print_path(path);
		path = NULL;
		tmp_end = tmp_end->end_parent;
	}
	tmp_paths = data->paths;
	while (tmp_paths)
	{
		print_path(tmp_paths->path);
		tmp_paths = tmp_paths->next;
	}
}
