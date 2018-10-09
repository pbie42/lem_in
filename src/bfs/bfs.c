/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:26:35 by pbie              #+#    #+#             */
/*   Updated: 2018/10/09 14:59:27 by pbie             ###   ########.fr       */
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

// t_qv		*add_to_q_end(t_qv *start, t_qv *new_link)
// {
// 		t_qv	*tmp;

// 		tmp = start;
// 		while(tmp->next)
// }

// void			bfs(t_data *data)
// {
// 	t_bfs		*bfs;
// 	int		len;
// 	int		i;

// 	bfs = (t_bfs *)malloc(sizeof(t_bfs));
// 	bfs->s_que = new_link(ht_search(data->map, data->start), 0);
// 	while (bfs->s_que)
// 	{
// 		bfs->tmp = bfs->s_que->room->link
// 		while(bfs->tmp)
// 		{
// 			bfs->tmp->
// 		}
// 	}
// }
