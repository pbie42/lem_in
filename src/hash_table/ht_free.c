/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:54:27 by pbie              #+#    #+#             */
/*   Updated: 2018/09/30 14:54:28 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void ht_free_item(t_h_item *i)
{
	free(i->key);
	free(i->value);
	free(i);
}

void ht_free_hash_table(t_h_table *ht)
{
	int i;
	t_h_item *item;

	i = 0;

	while (i < ht->size)
	{
		item = ht->items[i];
		if (item != NULL)
			ht_free_item(item);
		i++;
	}
	free(ht->items);
	free(ht);
}
