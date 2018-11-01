/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moved.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:57:03 by paul              #+#    #+#             */
/*   Updated: 2018/11/01 13:53:22 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_a_list		*new_moved(t_ant *ant)
{
	t_a_list	*tmp;

	tmp = (t_a_list *)malloc(sizeof(t_a_list));
	tmp->ant = ant;
	tmp->next = NULL;
	return (tmp);
}

t_a_list		*add_to_moved(t_a_list *moved, t_ant *ant, t_data *data)
{
	t_a_list	*tmp;

	tmp = moved;
	if (!tmp)
	{
		tmp = new_moved(ant);
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
			tmp->next = new_moved(ant);
		else
			tmp->ant->moved = TRUE;
	}
	return (moved);
}

void			free_moved(t_a_list *tmp)
{
	free(tmp->ant);
	free(tmp);
}

t_a_list		*remove_from_moved(t_a_list *moved, int ant_num)
{
	t_a_list	*tmp_list;
	t_a_list	*tmp;

	tmp_list = moved;
	if (tmp_list->ant->num == ant_num)
	{
		tmp = tmp_list;
		moved = tmp_list->next;
		free_moved(tmp);
		return (moved);
	}
	while (tmp_list->next)
	{
		if (tmp_list->next->ant->num == ant_num)
		{
			tmp = tmp_list->next;
			tmp_list->next = tmp_list->next->next;
			free_moved(tmp);
			return (moved);
		}
		tmp_list = tmp_list->next;
	}
	return (moved);
}

t_a_list		*clear_moved(t_a_list *moved, t_data *data)
{
	t_a_list	*tmp;
	t_a_list	*to_free;

	tmp = moved;
	while (tmp->next)
	{
		tmp->ant->moved = FALSE;
		tmp = tmp->next;
	}
	tmp->ant->moved = FALSE;
	return (moved);
}
