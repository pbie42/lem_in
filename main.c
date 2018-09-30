/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/09/30 16:45:31 by pbie             ###   ########.fr       */
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
		lines++;
	}
	if (lines <= 0)
		error();
	else
		ft_putendl("yeahh boiiii");

	ht = ht_new();
	ht_insert(ht, "paul", "bie");
	ht_insert(ht, "jennifer", "mee");
	ht_insert(ht, "jose", "bobs");
	ft_putendl(ht_search(ht, "paul"));
	ft_putendl(ht_search(ht, "jennifer"));
	ft_putendl(ht_search(ht, "jose"));
	ht_free_hash_table(ht);
	return (0);
}
