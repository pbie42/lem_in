/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:37 by pbie              #+#    #+#             */
/*   Updated: 2018/10/08 11:48:30 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool		is_link(char *line)
{
	char	**link;

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

t_bool		check_links(t_link *start, char *key)
{
	t_link	*tmp;

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

void		link_parse(t_parse *p, t_data *data)
{
	char	**link;
	t_room	*room;
	t_room	*linked_room;
	t_link	*new_link;

	room = NULL;
	linked_room = NULL;
	new_link = NULL;
	link = ft_strsplit(p->line, '-');
	room = ht_search(data->map, link[0]);
	linked_room = ht_search(data->map, link[1]);
	if (!room || !linked_room)
	{
		ft_free_matrix(link);
		return ;
	}
	new_link = l_new(linked_room->name);
	if (!check_links(room->link, new_link->key))
		l_add_end(room, new_link);
	new_link = NULL;
	new_link = l_new(room->name);
	if (!check_links(linked_room->link, new_link->key))
		l_add_end(linked_room, new_link);
	ft_free_matrix(link);
}
