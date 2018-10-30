/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/10/28 17:40:24 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_data *setup_data(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->ants = 0;
	data->ant_num = 1;
	data->moved = NULL;
	data->end_ants = 0;
	data->num_rooms = 0;
	data->start = NULL;
	data->end = NULL;
	data->map = NULL;
	data->paths = NULL;
	return (data);
}

void free_data(t_data *data)
{
	t_ants_list *tmp_ant_list;
	t_qv *tmp_qv;
	t_paths *tmp_path;

	ht_free_hash_table(data->map);
	// ft_putendl("freed hash table");
	if (data->start)
		free(data->start);
	if (data->end)
		free(data->end);
	// free(data->map);
	// while (data->moved)
	// {
	// 	tmp_ant_list = data->moved;
	// 	data->moved = data->moved->next;
	// 	free(tmp_ant_list);
	// }
	// free(data->moved);
	while (data->paths)
	{
		tmp_path = data->paths;
		while (tmp_path->path)
		{
			tmp_qv = tmp_path->path;
			tmp_path->path = tmp_path->path->next;
			free(tmp_qv);
		}
		data->paths = data->paths->next;
		free(tmp_path->path);
		free(tmp_path);
	}
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
	traversal(data);
	// ft_putendl("traversal done");
	free_data(data);

	// while(1){
	// 	;
	// }

	return (0);
}
