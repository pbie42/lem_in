/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:26:35 by pbie              #+#    #+#             */
/*   Updated: 2018/10/09 16:59:08 by pbie             ###   ########.fr       */
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
	if (!start)
		return (NULL);
	if (start->next)
	{
		start = start->next;
		return (start);
	}
	start->room = NULL;
	start->next = NULL;
	free (start);
	return (NULL);
}

void		add_to_q_end(t_qv *start, t_qv *new_link)
{
		t_qv	*tmp;

		tmp = start;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new_link;
}

void			bfs(t_data *data)
{
	t_bfs		*bfs;
	t_room	*tmp_room;
	t_bool	end_found;
	int		len;
	int		i;

	bfs = (t_bfs *)malloc(sizeof(t_bfs));
	bfs->s_que = new_link(ht_search(data->map, data->start), 0);
	tmp_room = ht_search(data->map, data->start);
	tmp_room->visited = TRUE;
	end_found = FALSE;
	while (bfs->s_que && !end_found)
	{
		bfs->links = bfs->s_que->room->link;
		while (bfs->links)
		{
			tmp_room = ht_search(data->map, bfs->links->key);
			if (!tmp_room->visited)
			{
				ft_putstr("room is: ");
				ft_putendl(tmp_room->name);
				if (!ft_strcmp(tmp_room->name, data->end))
				{
					end_found = TRUE;
					ft_putendl("END REACHED!!");
				}
				tmp_room->visited = TRUE;
				tmp_room->parent = bfs->s_que->room;
				add_to_q_end(bfs->s_que, new_link(tmp_room, bfs->s_que->level + 1));
			}
			tmp_room = NULL;
			bfs->links = bfs->links->next;
		}
		bfs->s_que = remove_from_queue(bfs->s_que);
	}
	if (!end_found)
		ft_putendl("END NEVER FOUND");
	ft_putendl("about to print path");
	print_path(ht_search(data->map, data->end));
}