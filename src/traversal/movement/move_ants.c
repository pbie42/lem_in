/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:17:38 by paul              #+#    #+#             */
/*   Updated: 2018/11/01 13:51:55 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	can_move(t_qv *tmp_path, t_data *data)
{
	if ((tmp_path->room->occupied ||
		!ft_strcmp(tmp_path->room->name, data->start) ||
		!ft_strcmp(tmp_path->room->name, data->end)) &&
		tmp_path->prev && !tmp_path->prev->room->occupied &&
		!tmp_path->prev->room->ant)
		return (TRUE);
	return (FALSE);
}

static t_move	*setup_move(t_qv *path)
{
	t_move		*m;

	m = malloc(sizeof(t_move));
	m->tmp_path = path;
	m->print_space = 0;
	m->moved_an_ant = FALSE;
	return (m);
}

t_bool			move_ants(t_qv *path, t_data *data)
{
	t_move		*m;
	t_bool		moved;

	m = setup_move(path);
	while (m->tmp_path)
	{
		if (can_move(m->tmp_path, data))
		{
			if ((!ft_strcmp(m->tmp_path->room->name, data->start)) &&
				data->ant_num <= data->ants)
				handle_start(m, data);
			else if (m->tmp_path->room->ant && !m->tmp_path->room->ant->moved)
				handle_move(m, data);
		}
		m->tmp_path = m->tmp_path->next;
	}
	moved = m->moved_an_ant;
	m->tmp_path = NULL;
	free(m);
	return (moved);
}
