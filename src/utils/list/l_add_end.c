/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_add_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:27:46 by pbie              #+#    #+#             */
/*   Updated: 2018/11/01 12:05:51 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_link;
	}
}
