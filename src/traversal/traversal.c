/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/10/16 22:38:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			add_to_moved(t_ants_list *moved, t_ant *ant)
{
	t_ants_list	*tmp;

	tmp = moved;
	if (!moved)
	{
		moved = (t_ants_list *)malloc(sizeof(t_ants_list));
		moved->ant = ant;
		moved->next = NULL;
	}
	else
	{
		while (moved->next)
			moved = moved->next;
		moved->next = (t_ants_list *)malloc(sizeof(t_ants_list));
		moved->ant = ant;
		moved->next->next = NULL;
	}
}

t_ant			*new_ant(t_data *data)
{
	t_ant		*new_ant;

	new_ant = (t_ant *)malloc(sizeof(t_ant));
	new_ant->moved = TRUE;
	new_ant->num = data->ant_num++;
	return (new_ant);
}

void			move_ants(t_qv *path, t_data *data)
{
	t_qv		*tmp_path;
	t_ant		*tmp_ant;

	tmp_path = path->next;
	tmp_ant = NULL;
	while (tmp_path)
	{
		// ft_putendl("ants while");
		// ft_putendlnbr("tmp_path->room->occupied", tmp_path->room->occupied);
		// ft_putendlnbr("tmp_path->room->start", tmp_path->room->start);
		// ft_putendlnbr("tmp_path->room->end", tmp_path->room->end);
		// ft_putstr(tmp_path->prev->room->name);
		// ft_putstr("->");
		// ft_putendl(tmp_path->room->name);
		// ft_putendlnbr("tmp_path->prev->room->occupied", tmp_path->prev->room->occupied);
		if ((tmp_path->room->occupied || !ft_strcmp(tmp_path->room->name, data->start) || !ft_strcmp(tmp_path->room->name, data->end)) &&
			tmp_path->prev && !tmp_path->prev->room->occupied)
		{
			ft_putendl("inside the big if");
			if (!ft_strcmp(tmp_path->room->name, data->start))
			{
				tmp_path->prev->room->ant = new_ant(data);
				ft_putchar('L');
				ft_putnbr(tmp_path->prev->room->ant->num);
				ft_putchar('-');
				ft_putstr(tmp_path->prev->room->name);
				ft_putchar(' ');
				add_to_moved(data->moved, tmp_path->prev->room->ant);
				tmp_path->prev->room->occupied = TRUE;
			}
			else if (!ft_strcmp(tmp_path->room->name, data->end))
			{
				data->end_ants++;
				tmp_ant = tmp_path->room->ant;
				ft_putchar('L');
				ft_putnbr(tmp_ant->num);
				ft_putchar('-');
				ft_putstr(tmp_path->prev->room->name);
				ft_putchar(' ');
				tmp_path->room->ant = NULL;
				free(tmp_ant);
			}
			else if (!tmp_path->room->ant->moved)
			{
				ft_putendl("ANT NOT MOVEDDDDDD");
				add_to_moved(data->moved, tmp_path->room->ant);
				ft_putchar('L');
				ft_putnbr(tmp_path->room->ant->num);
				ft_putchar('-');
				ft_putstr(tmp_path->prev->room->name);
				ft_putchar(' ');
				tmp_path->prev->room->ant = tmp_path->room->ant;
				tmp_path->prev->room->occupied = TRUE;
				tmp_path->room->ant = NULL;
				tmp_path->room->occupied = FALSE;
			}
		}
		tmp_path = tmp_path->next;
	}
}

void			clear_moved(t_ants_list *moved)
{
	t_ants_list *tmp;
	t_ants_list *to_free;

	tmp = moved;
	while (tmp)
	{
		tmp->ant->moved = FALSE;
		tmp->ant = NULL;
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	moved = NULL;
}

void			traversal(t_data *data)
{
	t_paths	*tmp_paths;
	int		i;

	i = 0;
	while (data->end_ants != data->ants && i < 10)
	{
		tmp_paths = data->paths;
		while (tmp_paths)
		{
			ft_putendl("tmp_paths");
			move_ants(tmp_paths->path, data);
			tmp_paths = tmp_paths->next;
		}
		clear_moved(data->moved);
		ft_putchar('\n');
		i++;
	}
}
