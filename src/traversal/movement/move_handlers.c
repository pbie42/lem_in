/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:19:34 by paul              #+#    #+#             */
/*   Updated: 2018/11/01 12:05:51 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ant *new_ant(t_data *data)
{
	t_ant *new_ant;

	new_ant = (t_ant *)malloc(sizeof(t_ant));
	if (!new_ant)
		ft_exit("Malloc fucking failed");
	new_ant->moved = TRUE;
	new_ant->num = data->ant_num++;
	return (new_ant);
}

static void handle_end(t_move *m, t_data *data)
{
	int ant_num;

	ant_num = m->tmp_path->room->ant->num;
	m->tmp_path->prev->room->ant = NULL;
	m->tmp_path->prev->room->occupied = FALSE;
	m->tmp_path->room->ant = NULL;
	m->tmp_path->room->occupied = FALSE;
	data->moved = remove_from_moved(data->moved, ant_num);
	data->end_ants++;
}

static void handle_regular(t_move *m)
{
	m->tmp_path->prev->room->ant = m->tmp_path->room->ant;
	m->tmp_path->prev->room->occupied = TRUE;
	m->tmp_path->room->ant = NULL;
	m->tmp_path->room->occupied = FALSE;
}

void handle_start(t_move *m, t_data *data)
{
	t_room *prev_room;

	prev_room = m->tmp_path->prev->room;
	prev_room->ant = new_ant(data);
	if (m->print_space != 0)
		ft_putchar(' ');
	print_move(prev_room->ant->num, prev_room->name);
	data->moved = add_to_moved(data->moved, prev_room->ant, data);
	prev_room->occupied = TRUE;
	m->moved_an_ant = TRUE;
	m->print_space++;
}

void handle_move(t_move *m, t_data *data)
{
	int ant_num;

	data->moved = add_to_moved(data->moved, m->tmp_path->room->ant, data);
	if (m->print_space != 0)
		ft_putchar(' ');
	print_move(m->tmp_path->room->ant->num, m->tmp_path->prev->room->name);
	if (!ft_strcmp(m->tmp_path->prev->room->name, data->end))
		handle_end(m, data);
	else
		handle_regular(m);
	m->moved_an_ant = TRUE;
	m->print_space++;
}
