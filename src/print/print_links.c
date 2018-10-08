/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:15:57 by pbie              #+#    #+#             */
/*   Updated: 2018/10/08 11:48:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		print_links(t_room *room)
{
	t_link	*tmp;

	tmp = room->link;
	if (!room->link)
	{
		ft_putendl("no start in print!!");
		return ;
	}
	ft_putstr(room->name);
	ft_putstr(" -> ");
	while (tmp->next)
	{
		ft_putstr(tmp->key);
		ft_putstr(" -> ");
		tmp = tmp->next;
	}
	ft_putendl(tmp->key);
}
