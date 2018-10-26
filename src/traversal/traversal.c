/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/10/26 18:14:55 by pbie             ###   ########.fr       */
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
	// if (ant->num > data->ants || ant->num < 0)
	// 	ft_exit("actual ant number problem in add to moved");
	if (!tmp)
	{
		// ft_putchar('\n');
		// ft_putchar('\n');
		// ft_putendl("new moved list");
		tmp = (t_ants_list *)malloc(sizeof(t_ants_list));
		// ft_putchar('\n');
		// ft_putchar('\n');
		tmp->ant = ant;
		tmp->next = NULL;
		// if (tmp->ant->num > data->ants || tmp->ant->num < 0)
		// 	ft_exit("ant number problem in NEW moved");
		return (tmp);
	}
	else
	{
		// ft_putendl("adding to end of moved list");
		while (tmp->next)
		{
			if (tmp->ant->num == ant->num)
			{
				tmp->ant->moved = TRUE;
				return (moved);
			}
			tmp = tmp->next;
		}
		// new = (t_ants_list *)malloc(sizeof(t_ants_list));
		// ft_putendl("after malloc");
		// if (!new)
		// 	ft_putendl("the new is nulllllllll");
		// ft_putendlnbr("tmp->ant->num ", tmp->ant->num);
		// ft_putendlnbr("tmp->ant->moved ", tmp->ant->moved);
		// new->ant = (t_ant *)malloc(sizeof(t_ant));
		// new->ant = ant;
		// new->next = NULL;
		// ft_putendl("after initalizing ant list tmp");
		// ft_putendlnbr("tmp->ant->num ", tmp->ant->num);
		// ft_putendlnbr("tmp->ant->moved ", tmp->ant->moved);
		// ft_putendlnbr("ant->num ", ant->num);
		// ft_putendlnbr("ant->moved ", ant->moved);
		// if (tmp->ant->num > data->ants || tmp->ant->num < 0)
		// 	ft_exit("ant number problem in add to moved");
		tmp->next = (t_ants_list *)malloc(sizeof(t_ants_list));
		tmp->next->ant = ant;
		tmp->next->next = NULL;
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

	// if (new_ant->num > data->ants || new_ant->num < 0)
	// 	ft_exit("TOO MANY ANTSSSS");
	return (new_ant);
}

void move_ants(t_qv *path, t_data *data)
{
	t_qv *tmp_path;
	t_ant *tmp_ant;
	t_bool finished;

	tmp_path = path;
	tmp_ant = NULL;
	finished = FALSE;
	// ft_putendl("in move_ants");
	while (tmp_path && !finished)
	{
		// ft_putendl("ants while");
		// ft_putendlnbr("tmp_path->room->occupied ", tmp_path->room->occupied);
		// ft_putendlnbr("tmp_path->room->start", tmp_path->room->start);
		// ft_putendlnbr("tmp_path->room->end", tmp_path->room->end);
		// ft_putstr(tmp_path->prev->room->name);
		// ft_putstr("->");
		// ft_putstr("room name: ");
		// ft_putendl(tmp_path->room->name);
		// if (tmp_path->room->ant)
		// {
		// 	ft_putendlnbr("tmp_path->room->ant->num ", tmp_path->room->ant->num);
		// 	ft_putendlnbr("tmp_path->room->ant->moved ", tmp_path->room->ant->moved);
		// }
		// ft_putendlnbr("tmp_path->prev->room->occupied ", tmp_path->prev->room->occupied);
		if ((tmp_path->room->occupied ||
			  !ft_strcmp(tmp_path->room->name, data->start) ||
			  !ft_strcmp(tmp_path->room->name, data->end)) &&
			 tmp_path->prev && !tmp_path->prev->room->occupied && !tmp_path->prev->room->ant)
		{
			// ft_putendl("inside the big if");

			// ft_putendlnbr("data->ants ", data->ants);
			// ft_putendlnbr("data->end_ants ", data->end_ants);
			// ft_putendlnbr("data->ant_num ", data->ant_num);
			// ft_putstr("is it the start? ");
			// ft_putendlnbr("ft_strcmp(tmp_path->room->name, data->start)", ft_strcmp(tmp_path->room->name, data->start));
			// ft_putstr("is ant num less or equal to ants? ");
			// ft_putendlnbr("data->ant_num <= data->ants ", data->ant_num <= data->ants);
			// ft_putendlnbr("ft_strcmp(tmp_path->room->name, data->end) ", ft_strcmp(tmp_path->room->name, data->end));
			// if (!tmp_path)
			// 	ft_putendl("no room homie");
			// else
			// 	ft_putendl("is a path");
			if ((!ft_strcmp(tmp_path->room->name, data->start)) && data->ant_num <= data->ants)
			{
				// ft_putchar('\n');
				// ft_putendl("in start if");
				tmp_path->prev->room->ant = new_ant(data);
				// ft_putendl("new ant put in prev room");
				// if (tmp_path->prev->room->ant->num > data->ants || tmp_path->prev->room->ant->num < 0)
				// 	ft_exit("Ant num problem in start if");
				ft_putchar('L');
				ft_putnbr(tmp_path->prev->room->ant->num);
				ft_putchar('-');
				ft_putstr(tmp_path->prev->room->name);
				ft_putchar(' ');
				// ft_putendl("about to add to moved");
				data->moved = add_to_moved(data->moved, tmp_path->prev->room->ant, data);
				// ft_putendl("after add to moved");
				tmp_path->prev->room->occupied = TRUE;
			}
			else if (!ft_strcmp(tmp_path->room->name, data->end))
			{
				// ft_putchar('\n');
				// ft_putendl("in end if");
				data->end_ants++;
				// tmp_ant = tmp_path->room->ant;
				// if (tmp_ant->num > data->ants || tmp_ant->num < 0)
				// 	ft_exit("WE GOT A PROBLEM CHIEF");
				ft_putchar('L');
				ft_putnbr(tmp_ant->num);
				ft_putchar('-');
				ft_putstr(tmp_path->prev->room->name);
				ft_putchar(' ');
				// tmp_path->room->ant = NULL;
				// free(tmp_ant);
			}
			else if (tmp_path->room->ant && !tmp_path->room->ant->moved)
			{
				// ft_putchar('\n');
				// ft_putendl("ANT NOT MOVEDDDDDD");
				data->moved = add_to_moved(data->moved, tmp_path->room->ant, data);
				ft_putchar('L');
				ft_putnbr(tmp_path->room->ant->num);
				ft_putchar('-');
				ft_putstr(tmp_path->prev->room->name);
				ft_putchar(' ');
				if (!ft_strcmp(tmp_path->prev->room->name, data->end))
				{
					// ft_putendl("not moved end room");
					// tmp_ant = tmp_path->room->ant;
					// if (tmp_ant->num > data->ants || tmp_ant->num < 0)
					// 	ft_exit("WE GOT A PROBLEM BOSS");
					// free(tmp_ant);
					tmp_path->prev->room->ant = NULL;
					tmp_path->prev->room->occupied = FALSE;
					tmp_path->room->ant = NULL;
					tmp_path->room->occupied = FALSE;
					data->end_ants++;
				}
				else
				{
					// ft_putendl("not moved regular room");
					// if (tmp_path->room->ant->num > data->ants || tmp_path->room->ant->num < 0)
					// 	ft_exit("WE GOT A PROBLEM BOSS");
					tmp_path->prev->room->ant = tmp_path->room->ant;
					tmp_path->prev->room->occupied = TRUE;
					tmp_path->room->ant = NULL;
					tmp_path->room->occupied = FALSE;
				}
				if (data->ant_num - 1 == data->ants)
					finished = TRUE;
				// ft_putendl("getting here");
				// ft_putendlnbr("data->end_ants ", data->end_ants);
				// ft_putendlnbr("data->ant_num ", data->ant_num);
			}
		}
		// ft_putchar('\n');
		// ft_putendl("about to loop move ants");
		tmp_path = tmp_path->next;
	}
	// ft_putendl("leaving move ants");
}

t_ants_list *clear_moved(t_ants_list *moved, t_data *data)
{
	t_ants_list *tmp;
	t_ants_list *to_free;

	tmp = moved;
	while (tmp->next)
	{
		// ft_putendlnbr("tmp->ant->num ", tmp->ant->num);
		// ft_putendlnbr("tmp->ant->moved ", tmp->ant->moved);
		tmp->ant->moved = FALSE;
		// if (tmp->ant->num > data->ants || tmp->ant->num < 0)
		// 	ft_exit("ant number problem in clear");
		tmp = tmp->next;
	}
	tmp->ant->moved = FALSE;
	return (moved);
}

void traversal(t_data *data)
{
	t_paths *tmp_paths;
	t_bool finished;
	int i;

	i = 0;
	finished = FALSE;
	while (data->end_ants < data->ants)
	{
		tmp_paths = data->paths;
		while (tmp_paths)
		{
			// ft_putchar('\n');
			// ft_putendl("tmp_paths!!!!!!!!!");
			// ft_putchar('\n');
			move_ants(tmp_paths->path, data);
			tmp_paths = tmp_paths->next;
		}
		// if (data->ant_num - 1 == data->ants)
		// {
		// 	finished = TRUE;
		// 	ft_putendlnbr("data->ants ", data->ants);
		// 	ft_putendlnbr("data->end_ants ", data->end_ants);
		// 	ft_putendlnbr("data->ant_num ", data->ant_num);
		// 	ft_putendl("should be ending");
		// }
		// ft_putchar('\n');
		// ft_putendl("about to clear moved");
		// ft_putendlnbr("data->ants ", data->ants);
		// ft_putendlnbr("data->end_ants ", data->end_ants);
		// ft_putendlnbr("data->ant_num ", data->ant_num);

		data->moved = clear_moved(data->moved, data);
		// ft_putendl("cleared moved");
		ft_putchar('\n');
		i++;
	}
}
