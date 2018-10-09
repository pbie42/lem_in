/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:38:40 by pbie              #+#    #+#             */
/*   Updated: 2018/10/09 13:57:27 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_qv		*new_link(t_room *room, int level)
{
	t_qv *new_qv;

	new_qv = (t_qv *)malloc(sizeof(t_qv));
	new_qv->room = room;
	new_qv->level = level;
	new_qv->next = NULL;
	return (new_qv);
}