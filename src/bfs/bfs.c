/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:26:35 by pbie              #+#    #+#             */
/*   Updated: 2018/10/09 21:14:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_qv		*which_queue(t_qv *start, t_qv *end)
{
	int	s_len;
	int	e_len;

	s_len = list_length(start);
	e_len = list_length(end);
	if (s_len >= e_len)
		return (start);
	return (end);
}

t_qv		*remove_from_queue(t_qv *start)
{
	t_qv	*tmp;

	if (!start)
		return (NULL);
	if (start->next)
	{
		tmp = start;
		start = start->next;
		free(tmp);
		return (start);
	}
	start->room = NULL;
	start->next = NULL;
	free (start);
	return (NULL);
}

void		add_to_q(t_qv *start, t_qv *new_link)
{
	t_qv	*tmp;

	tmp = start;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new_link;
}

void		add_end_parent(t_room *end, t_room *parent)
{
	t_room *tmp;
	if (!end->end_parent)
		end->end_parent = parent;
	else
	{
		tmp = end;
		while (tmp->end_parent)
			tmp = tmp->end_parent;
		tmp->end_parent = parent;
	}
	tmp = end;
	while (tmp->end_parent)
	{
		ft_putstr("end parent: ");
		ft_putendl(tmp->end_parent->name);
		tmp = tmp->end_parent;
	}
}

void			bfs(t_data *data)
{
	t_bfs		*bfs;
	t_room	*tmp_room;
	t_bool	end_found;

	bfs = (t_bfs *)malloc(sizeof(t_bfs));
	bfs->s_que = new_link(ht_search(data->map, data->start), 0);
	tmp_room = ht_search(data->map, data->start);
	tmp_room->visited = TRUE;
	end_found = FALSE;
	while (bfs->s_que)
	{
		bfs->links = bfs->s_que->room->link;
		while (bfs->links)
		{
			tmp_room = ht_search(data->map, bfs->links->key);
			if (!tmp_room->visited)
			{
				if (!ft_strcmp(tmp_room->name, data->end))
				{
					end_found = TRUE;
					add_end_parent(tmp_room, bfs->s_que->room);
				}
				else
				{
					tmp_room->visited = TRUE;
					tmp_room->parent = bfs->s_que->room;
					add_to_q(bfs->s_que, new_link(tmp_room, bfs->s_que->level + 1));
				}
			}
			tmp_room = NULL;
			bfs->links = bfs->links->next;
		}
		bfs->s_que = remove_from_queue(bfs->s_que);
	}
	if (!end_found)
		path_error("end", data, bfs);
	free(bfs->s_que);
	free(bfs);
	ft_putendl("about to print paths");
}
