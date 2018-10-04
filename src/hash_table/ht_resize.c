/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:54:50 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 11:23:08 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ht_resize(t_h_table *ht, const int base_size)
{
	t_h_table	*new_ht;
	t_h_item	*item;
	t_h_item	**tmp_items;
	int			tmp_size;
	int			i;

	if (base_size < HT_INITIAL_BASE_SIZE)
		return ;
	new_ht = ht_new_sized(base_size);
	i = 0;
	while (i < ht->size)
	{
		item = ht->items[i];
		if (item != NULL)
			ht_insert(new_ht, item->key, item->value);
		i++;
	}
	ht->base_size = new_ht->base_size;
	ht->count = new_ht->count;
	tmp_size = ht->size;
	ht->size = new_ht->size;
	new_ht->size = tmp_size;
	tmp_items = ht->items;
	ht->items = new_ht->items;
	new_ht->items = tmp_items;
	ht_free_hash_table(new_ht);
}

void			ht_resize_up(t_h_table *ht)
{
	const int new_size = ht->base_size * 2;

	ht_resize(ht, new_size);
}
