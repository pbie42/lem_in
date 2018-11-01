/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/11/01 12:05:51 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
