/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/10/05 14:53:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_data *setup_data(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->ants = 0;
	data->num_rooms = 0;
	data->start = NULL;
	data->end = NULL;
	data->map = NULL;
	return (data);
}

int main(void)
{
	t_data *data;
	t_h_table *ht;
	t_room *tmp_room;

	data = NULL;
	data = setup_data();
	if (data == NULL)
		ft_putendl("data is null");
	parse(data);

	tmp_room = ht_search(data->map, "0");
	print_links(tmp_room);
	// ft_putendl("about to show 0");
	// ft_putendl(tmp_room->name);
	// tmp_room->start = TRUE;
	// ft_putendlnbr("tmp_room->start ", tmp_room->start);
	// ft_putendlnbr("tmp_room->end ", tmp_room->end);
	// ft_putendlnbr("tmp_room->occupied ", tmp_room->occupied);
	// tmp_room = ht_search(data->map, "1");
	// ft_putendl(tmp_room->name);
	// ft_putendlnbr("tmp_room->start ", tmp_room->start);
	// ft_putendlnbr("tmp_room->end ", tmp_room->end);
	// ft_putendlnbr("tmp_room->occupied ", tmp_room->occupied);
	// tmp_room = ht_search(data->map, "2");
	// ft_putendl(tmp_room->name);
	// ft_putendlnbr("tmp_room->start ", tmp_room->start);
	// ft_putendlnbr("tmp_room->end ", tmp_room->end);
	// ft_putendlnbr("tmp_room->occupied ", tmp_room->occupied);
	// tmp_room = ht_search(data->map, "3");
	// ft_putendl(tmp_room->name);
	// ft_putendlnbr("tmp_room->start ", tmp_room->start);
	// ft_putendlnbr("tmp_room->end ", tmp_room->end);
	// ft_putendlnbr("tmp_room->occupied ", tmp_room->occupied);

	ht_free_hash_table(data->map);
	if (data->start)
		free(data->start);
	free(data);
	
	// while(1){
	// 	;
	// }
	
	return (0);
}
