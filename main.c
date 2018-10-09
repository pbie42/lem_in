/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/10/09 22:04:44 by pbie             ###   ########.fr       */
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
	data->paths = NULL;
	return (data);
}

void	free_data(t_data *data)
{
	ht_free_hash_table(data->map);
	if (data->start)
		free(data->start);
	if (data->end)
		free(data->end);
	free(data);
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
	bfs(data);
	construct_paths(ht_search(data->map, data->end), data);
	// ft_putendl("about to print links");
	// tmp_room = ht_search(data->map, data->start);
	// print_links(tmp_room);
	free_data(data);
	
	// while(1){
	// 	;
	// }
	
	return (0);
}
