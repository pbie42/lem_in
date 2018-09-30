/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/09/30 17:26:30 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int main(void)
{
	char *line;
	int lines;
	t_h_table *ht;

	while (ft_get_next_line(0, &line) == 1)
	{
		ft_putendl(line);
		free(line);
		lines++;
	}
	free(line);
	if (lines <= 0)
		error();
	else
		ft_putendl("yeahh boiiii");

	ht = ht_new();
	t_room *paul = malloc(sizeof(t_room));
	paul->name = ft_strdup("paul");
	paul->start = FALSE;
	paul->end = TRUE;
	paul->occupied = FALSE;
	ht_insert(ht, "paul", paul);
	paul = NULL;
	// ht_insert(ht, "jennifer", "mee");
	// ht_insert(ht, "jose", "bobs");
	t_room *tmp_room = ht_search(ht, "paul");
	ft_putendl(tmp_room->name);
	ft_putendlnbr("tmp_room->start", tmp_room->start);
	ft_putendlnbr("tmp_room->end", tmp_room->end);
	ft_putendlnbr("tmp_room->occupied", tmp_room->occupied);
	// ft_putendl(ht_search(ht, "jennifer")->name);
	// ft_putendl(ht_search(ht, "jose")->name);
	ht_free_hash_table(ht);
	return (0);
}
