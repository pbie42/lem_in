/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/10/30 16:41:44 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_ants_list *add_to_moved(t_ants_list *moved, t_ant *ant, t_data *data)
{
	t_ants_list *tmp;
	t_ants_list *new;
	int num_stash;
	t_bool moved_stash;

	tmp = moved;
	if (!tmp)
	{
		tmp = (t_ants_list *)malloc(sizeof(t_ants_list));
		tmp->ant = ant;
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		while (tmp->next)
		{
			if (tmp->ant->num == ant->num)
			{
				tmp->ant->moved = TRUE;
				return (moved);
			}
			tmp = tmp->next;
		}
		if (tmp->ant->num != ant->num)
		{
			tmp->next = (t_ants_list *)malloc(sizeof(t_ants_list));
			tmp->next->ant = ant;
			tmp->next->next = NULL;
		}
		else
			tmp->ant->moved = TRUE;
	}
	return (moved);
}

t_ant *new_ant(t_data *data)
{
	t_ant *new_ant;

	new_ant = (t_ant *)malloc(sizeof(t_ant));
	if (!new_ant)
		ft_exit("Malloc fucking failed");
	new_ant->moved = TRUE;
	new_ant->num = data->ant_num++;
	return (new_ant);
}

t_ants_list *remove_from_moved(t_ants_list *moved, int ant_num)
{
	t_ants_list *tmp_list;
	t_ants_list *tmp;
	t_ant *tmp_ant;

	tmp_list = moved;
	if (tmp_list->ant->num == ant_num)
	{
		tmp = tmp_list;
		moved = tmp_list->next;
		free(tmp->ant);
		free(tmp);
		return (moved);
	}
	while (tmp_list->next)
	{
		if (tmp_list->next->ant->num == ant_num)
		{
			tmp = tmp_list->next;
			tmp_list->next = tmp_list->next->next;
			free(tmp->ant);
			free(tmp);
			return (moved);
		}
		tmp_list = tmp_list->next;
	}
	return (moved);
}

t_bool move_ants(t_qv *path, t_data *data)
{
	t_qv *tmp_path;
	t_ant *tmp_ant;
	int ant_num;
	int test;
	t_bool moved_an_ant;

	tmp_path = path;
	tmp_ant = NULL;
	test = 0;
	moved_an_ant = FALSE;
	while (tmp_path)
	{
		if ((tmp_path->room->occupied ||
			!ft_strcmp(tmp_path->room->name, data->start) ||
			!ft_strcmp(tmp_path->room->name, data->end)) &&
			tmp_path->prev && !tmp_path->prev->room->occupied &&
			!tmp_path->prev->room->ant)
		{
			if ((!ft_strcmp(tmp_path->room->name, data->start)) &&
				data->ant_num <= data->ants)
			{
				tmp_path->prev->room->ant = new_ant(data);
				if (test != 0)
					ft_putchar(' ');
				test++;
				print_move(tmp_path->prev->room->ant->num, tmp_path->prev->room->name);
				data->moved = add_to_moved(data->moved, tmp_path->prev->room->ant, data);
				moved_an_ant = TRUE;
				tmp_path->prev->room->occupied = TRUE;
			}
			else if (tmp_path->room->ant && !tmp_path->room->ant->moved)
			{
				data->moved = add_to_moved(data->moved, tmp_path->room->ant, data);
				if (test != 0)
					ft_putchar(' ');
				test++;
				print_move(tmp_path->room->ant->num, tmp_path->prev->room->name);
				moved_an_ant = TRUE;
				if (!ft_strcmp(tmp_path->prev->room->name, data->end))
				{
					ant_num = tmp_path->room->ant->num;
					tmp_path->prev->room->ant = NULL;
					tmp_path->prev->room->occupied = FALSE;
					tmp_path->room->ant = NULL;
					tmp_path->room->occupied = FALSE;
					data->moved = remove_from_moved(data->moved, ant_num);
					data->end_ants++;
				}
				else
				{
					tmp_path->prev->room->ant = tmp_path->room->ant;
					tmp_path->prev->room->occupied = TRUE;
					tmp_path->room->ant = NULL;
					tmp_path->room->occupied = FALSE;
				}
			}
		}
		tmp_path = tmp_path->next;
	}
	return (moved_an_ant);
}

t_ants_list *clear_moved(t_ants_list *moved, t_data *data)
{
	t_ants_list *tmp;
	t_ants_list *to_free;

	tmp = moved;
	while (tmp->next)
	{
		tmp->ant->moved = FALSE;
		tmp = tmp->next;
	}
	tmp->ant->moved = FALSE;
	return (moved);
}

void traversal(t_data *data)
{
	t_paths *tmp_paths;
	int test;
	t_bool moved;

	while (data->end_ants < data->ants)
	{
		tmp_paths = data->paths;
		test = 0;
		moved = FALSE;
		while (tmp_paths)
		{
			if (test != 0 && moved)
				ft_putchar(' ');
			moved = move_ants(tmp_paths->path, data);
			tmp_paths = tmp_paths->next;
			test++;
		}
		if (data->moved)
			data->moved = clear_moved(data->moved, data);
		ft_putchar('\n');
	}
}
