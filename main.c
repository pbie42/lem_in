/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/11/01 13:40:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_data			*setup_data(void)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	data->ants = 0;
	data->ant_num = 1;
	data->moved = NULL;
	data->end_ants = 0;
	data->num_rooms = 0;
	data->start = NULL;
	data->end = NULL;
	data->paths = NULL;
	data->rooms = NULL;
	return (data);
}

void			free_rooms(t_data *data)
{
	t_qv		*tmp_rooms;

	while (data->rooms)
	{
		tmp_rooms = data->rooms;
		data->rooms = data->rooms->next;
		free(tmp_rooms->room->name);
		l_free(tmp_rooms->room->link);
		free(tmp_rooms->room);
		free(tmp_rooms);
	}
	free(data->rooms);
}

void			free_data(t_data *data)
{
	t_a_list	*tmp_ant_list;
	t_qv		*tmp_qv;
	t_paths		*tmp_path;

	free_rooms(data);
	if (data->start)
		free(data->start);
	if (data->end)
		free(data->end);
	while (data->paths)
	{
		tmp_path = data->paths;
		while (tmp_path->path)
		{
			tmp_qv = tmp_path->path;
			tmp_path->path = tmp_path->path->next;
			free(tmp_qv);
		}
		data->paths = data->paths->next;
		free(tmp_path->path);
		free(tmp_path);
	}
	free(data);
}

int				main(void)
{
	t_data		*data;
	t_room		*tmp_room;

	data = NULL;
	data = setup_data();
	if (data == NULL)
		ft_putendl("data is null");
	parse(data);
	bfs(data);
	construct_paths(find_room(data->rooms, data->end), data);
	traversal(data);
	free_data(data);
	return (0);
}
