/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:06:59 by paul              #+#    #+#             */
/*   Updated: 2018/11/01 12:05:51 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_qv		*which_queue(t_qv *start, t_qv *end)
{
	int	s_len;
	int	e_len;

	s_len = list_length(start);
	e_len = list_length(end);
	if (s_len >= e_len)
		return (start);
	return (end);
}

t_qv		*remove_from_queue(t_qv *start)
{
	t_qv	*tmp;

	if (!start)
		return (NULL);
	if (start->next)
	{
		tmp = start;
		start = start->next;
		free(tmp);
		return (start);
	}
	start->room = NULL;
	start->next = NULL;
	free (start);
	return (NULL);
}

void		add_to_q(t_qv *start, t_qv *new_link)
{
	t_qv	*tmp;

	tmp = start;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new_link;
}
