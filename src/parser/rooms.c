/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:40 by pbie              #+#    #+#             */
/*   Updated: 2018/10/29 23:29:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool is_room(const char *line)
{
	char **room;

	if (line[0] == 'L')
		return (FALSE);
	if (ft_wordcount(line, ' ') != 3)
		return (FALSE);
	room = ft_strsplit(line, ' ');
	if (!ft_is_num(room[1]))
	{
		ft_putendl("about to free matrix not num room 1");
		ft_free_matrix(room);
		return (FALSE);
	}
	if (!ft_is_num(room[2]))
	{
		ft_putendl("about to free matrix not num room 2");
		ft_free_matrix(room);
		return (FALSE);
	}
	ft_putendl("about to free matrix is room");
	ft_free_matrix(room);
	ft_putendl("free matrix done is room");
	return (TRUE);
}

t_room *setup_room(char *name, t_bool start_done, t_bool end_done)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	room->name = ft_strdup(name);
	room->start = FALSE;
	room->end = FALSE;
	room->occupied = FALSE;
	room->visited = FALSE;
	room->parent = NULL;
	room->end_parent = NULL;
	room->link = NULL;
	room->ant = NULL;
	return (room);
}

void room_parse(t_parse *p, t_data *data)
{
	char **s_room;
	t_room *room;
	t_bool start;
	t_bool end;

	start = FALSE;
	ft_putendl("about to str split");
	s_room = ft_strsplit(p->line, ' ');
	ft_putendl("str split done");
	if (p->start_found && !data->start)
	{
		start = TRUE;
		data->start = ft_strdup(s_room[0]);
		ft_putendl(data->start);
	}
	if (p->end_found && !data->end)
	{
		end = TRUE;
		data->end = ft_strdup(s_room[0]);
		ft_putendl(data->end);
	}
	ft_putendl("about to insert to ht");
	ht_insert(data->map, s_room[0], setup_room(s_room[0], start, end));
	ft_putendl("about to free s_room");
	ft_putendl("5");
	ft_free_matrix(s_room);
	p->rooms++;
}
