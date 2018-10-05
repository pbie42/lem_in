/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:37 by pbie              #+#    #+#             */
/*   Updated: 2018/10/05 14:52:18 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool		is_link(char* line)
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
	ft_putendl("found room");
	linked_room = ht_search(data->map, link[1]);
	ft_putendl("found linked room");
	if (!room || !linked_room)
		return ;
	ft_putendl("about to make new link");
	new_link = l_new(linked_room->name);
	ft_putendl("about to add to end");
	l_add_end(room, new_link);
	ft_putstr("room->link->key: ");
	ft_putendl(room->link->key);
}
