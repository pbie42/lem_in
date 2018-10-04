/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:40 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 21:34:28 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool	is_room(const char *line)
{
	char	**room;

	if (line[0] == 'L')
		return (FALSE);
	if (ft_wordcount(line, ' ') != 3)
		return (FALSE);
	room = ft_strsplit(line, ' ');
	if (!ft_is_pos_num(room[1]))
	{
		ft_free_matrix(room);
		return (FALSE);
	}
	if (!ft_is_pos_num(room[2]))
	{
		ft_free_matrix(room);
		return (FALSE);
	}
	ft_free_matrix(room);
	return (TRUE);
}

t_room	*setup_room(char *name, t_bool start_done, t_bool end_done)
{
	t_room *room;

	room = malloc(sizeof(t_room));
	room->name = ft_strdup(name);
	room->start = FALSE;
	room->end = FALSE;
	room->occupied = FALSE;
	return (room);
}

void	room_parse(t_parse *p, t_data *data)
{
	char	**s_room;
	t_room *room;
	t_bool start_done;
	t_bool end_done;

	start_done = FALSE;
	s_room = ft_strsplit(p->line, ' ');
	// if (p->start_found && !ft_strcmp(data->start, ""))
	// {
	// 	start_done = TRUE;
	// 	p->start_found = FALSE;
	// 	data->start = ft_strdup(s_room[0]);
	// }
	// if (p->end_found && !ft_strcmp(data->start, ""))
	// {
	// 	end_done = TRUE;
	// 	p->start_found = FALSE;
	// 	data->start = ft_strdup(s_room[0]);
	// }
	// data->start = ft_strdup(s_room[0]);
	ft_putendl(s_room[0]);
	ht_insert(data->map, s_room[0], setup_room(s_room[0], start_done, end_done));
	p->rooms++;
	ft_free_matrix(s_room);
}
