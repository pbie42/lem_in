/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_add_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:27:46 by pbie              #+#    #+#             */
/*   Updated: 2018/10/05 14:51:06 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_link		*l_new(char *key)
{
	t_link	*new_link;

	new_link = (t_link*)malloc(sizeof(t_link));
	new_link->key = ft_strdup(key);
	new_link->next = NULL;
	return (new_link);
}

void			l_add_end(t_room *room, t_link *new_link)
{
	t_link		*tmp;

	tmp = room->link;
	if (!room->link)
		room->link = new_link;
	else if (tmp->next == NULL)
		tmp->next = new_link;
	else
	{
		ft_putendl("about to while");
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_link;
	}
	ft_putendl("leaving add end");
}