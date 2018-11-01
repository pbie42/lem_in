/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/11/01 17:52:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		extra_rooms(t_paths *paths)
{
	int	shortest;
	int	extra;
	t_paths	*tmp_paths;

	shortest = shortest_len(paths);
	tmp_paths = paths;
	extra = 0;
	while (tmp_paths)
	{
		if (tmp_paths->use && tmp_paths->len > shortest)
			extra += tmp_paths->len - shortest;
		tmp_paths = tmp_paths->next;
	}
	return (extra);
}

void		disable_longest(t_paths *paths)
{
	t_paths	*tmp_paths;
	t_paths	*longest;

	tmp_paths = paths;
	longest = paths;
	while (tmp_paths)
	{
		if (tmp_paths->use && tmp_paths->len > longest->len)
			longest = tmp_paths;
		tmp_paths = tmp_paths->next;
	}
	longest->use = FALSE;
}

void		traversal(t_data *data)
{
	t_paths	*tmp_paths;
	t_bool	moved;
	int		print;

	data->num_paths = cnt_set_lens(data->paths);
	data->av_paths = data->num_paths;
	if (data->num_paths > 1)
		data->extra_rooms = extra_rooms(data->paths);
	while (data->end_ants < data->ants)
	{
		tmp_paths = data->paths;
		print = 0;
		moved = FALSE;
		while (tmp_paths)
		{
			if (print != 0 && moved)
				ft_putchar(' ');
			moved = move_ants(tmp_paths->path, data);
			tmp_paths = tmp_paths->next;
			print++;
		}
		if (data->moved)
			data->moved = clear_moved(data->moved, data);
		ft_putchar('\n');
	}
}
