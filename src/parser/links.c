/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:37 by pbie              #+#    #+#             */
/*   Updated: 2018/10/30 20:00:28 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool is_link(char *line)
{
	char **link;

	if (line[0] == 'L')
		return (FALSE);
	if (ft_wordcount(line, '-') != 2)
		return (FALSE);
	if (ft_check_white(line))
		return (FALSE);
	link = ft_strsplit(line, '-');
	if (link[1][0] == 'L')
	{
		ft_free_matrix(link);
		return (FALSE);
	}
	ft_free_matrix(link);
	return (TRUE);
}

t_bool check_links(t_link *start, char *key)
{
	t_link *tmp;

	tmp = start;
	if (!start)
		return (FALSE);
	if (!ft_strcmp(key, tmp->key))
		return (TRUE);
	while (tmp->next)
	{
		if (!ft_strcmp(key, tmp->next->key))
			return (TRUE);
		tmp = tmp->next;
	}
	if (!ft_strcmp(key, tmp->key))
		return (TRUE);
	return (FALSE);
}

void handle_link(t_room *for_new, t_room *for_end)
{
	t_link *new_link;

	new_link = l_new(for_new->name);
	if (!check_links(for_end->link, new_link->key))
		l_add_end(for_end, new_link);
	else
	{
		free(new_link->key);
		free(new_link);
	}
}

void link_parse(t_parse *p, t_data *data)
{
	char **link;
	t_room *room;
	t_room *linked_room;
	t_link *new_link;

	link = ft_strsplit(p->line, '-');
	room = find_room(data->rooms, link[0]);
	linked_room = find_room(data->rooms, link[1]);
	if (!room || !linked_room)
	{
		ft_free_matrix(link);
		return ;
	}
	handle_link(linked_room, room);
	handle_link(room, linked_room);
	ft_free_matrix(link);
}
