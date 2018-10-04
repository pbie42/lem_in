/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 18:30:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int main(void)
{
	t_data *data;
	t_h_table *ht;

	data = NULL;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		ft_putendl("data is null");
	parse(data);
	free(data);
	ht = ht_new();

	t_room *paul = malloc(sizeof(t_room));
	paul->name = ft_strdup("paul");
	paul->start = FALSE;
	paul->end = TRUE;
	paul->occupied = FALSE;
	ht_insert(ht, "paul", paul);
	paul = NULL;
	t_room *tmp_room = ht_search(ht, "paul");
	ft_putendl(tmp_room->name);
	ft_putendlnbr("tmp_room->start", tmp_room->start);
	ft_putendlnbr("tmp_room->end", tmp_room->end);
	ft_putendlnbr("tmp_room->occupied", tmp_room->occupied);
	ht_free_hash_table(ht);
	
	// while(1){
	// 	;
	// }
	
	return (0);
}
