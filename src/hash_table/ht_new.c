/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:54:03 by pbie              #+#    #+#             */
/*   Updated: 2018/09/30 16:29:02 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_h_item *ht_new_item(const char *k, const char *v)
{
	t_h_item *item;

	item = malloc(sizeof(t_h_item));
	item->key = ft_strdup(k);
	item->value = ft_strdup(v);
	return (item);
}

t_h_table *ht_new_sized(const int base_size)
{
	t_h_table *ht;

	ht = malloc(sizeof(t_h_table));
	ht->base_size = base_size;
	ht->size = ft_next_prime(ht->base_size);
	ht->count = 0;
	ht->items = calloc((size_t)ht->size, sizeof(t_h_item *));
	return (ht);
}

t_h_table *ht_new(void)
{
	return (ht_new_sized(HT_INITIAL_BASE_SIZE));
}
