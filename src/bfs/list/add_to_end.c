/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:01:41 by pbie              #+#    #+#             */
/*   Updated: 2018/11/01 12:05:51 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_to_end(t_qv *head, t_qv *new_link)
{
	t_qv		*tmp;

	tmp = head;
	if (!head)
	{
		head = new_link;
		head->prev = NULL;
	}
	else if (!head->next)
	{
		head->next = new_link;
		new_link->prev = head;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_link;
		new_link->prev = tmp;
	}
}
