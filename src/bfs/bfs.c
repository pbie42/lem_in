/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:26:35 by pbie              #+#    #+#             */
/*   Updated: 2018/11/01 12:05:51 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_end_parent(t_bfs *bfs)
{
	t_room *tmp;

	bfs->end_found = TRUE;
	if (!bfs->tmp_room->end_parent)
		bfs->tmp_room->end_parent = bfs->s_que->room;
	else
	{
		tmp = bfs->tmp_room;
		while (tmp->end_parent)
			tmp = tmp->end_parent;
		tmp->end_parent = bfs->s_que->room;
	}
	tmp = bfs->tmp_room;
	while (tmp->end_parent)
		tmp = tmp->end_parent;
}

static void handle_add_q(t_bfs *bfs)
{
	bfs->tmp_room->visited = TRUE;
	bfs->tmp_room->parent = bfs->s_que->room;
	add_to_q(bfs->s_que, new_link(bfs->tmp_room, bfs->s_que->level + 1));
}

static t_bfs *setup_bfs(t_data *data)
{
	t_bfs *bfs;

	bfs = (t_bfs *)malloc(sizeof(t_bfs));
	bfs->s_que = new_link(find_room(data->rooms, data->start), 0);
	bfs->tmp_room = find_room(data->rooms, data->start);
	bfs->tmp_room->visited = TRUE;
	bfs->end_found = FALSE;
	return (bfs);
}

void			bfs(t_data *data)
{
	t_bfs		*bfs;

	bfs = setup_bfs(data);
	while (bfs->s_que)
	{
		bfs->links = bfs->s_que->room->link;
		while (bfs->links)
		{
			bfs->tmp_room = find_room(data->rooms, bfs->links->key);
			if (!bfs->tmp_room->visited)
			{
				if (!ft_strcmp(bfs->tmp_room->name, data->end))
					add_end_parent(bfs);
				else
					handle_add_q(bfs);
			}
			bfs->tmp_room = NULL;
			bfs->links = bfs->links->next;
		}
		bfs->s_que = remove_from_queue(bfs->s_que);
	}
	if (!bfs->end_found)
		path_error("end", data, bfs);
	free(bfs->s_que);
	free(bfs);
}
