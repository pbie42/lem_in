/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:54:40 by pbie              #+#    #+#             */
/*   Updated: 2018/09/30 16:45:03 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int ht_hash(const char *s, const int a, const int m)
{
	long hash;
	int len_s;
	int i;

	hash = 0;
	len_s = ft_strlen(s);
	i = 0;
	while (i < len_s)
	{
		hash += ft_pow(a, len_s - (i + 1)) * s[i];
		hash = hash % m;
		i++;
	}
	return ((int)hash);
}

int ht_get_hash(const char *s, const int buckets, const int attempt)
{
	int hash_a;
	int hash_b;

	hash_a = ht_hash(s, HT_PRIME_1, buckets);
	hash_b = ht_hash(s, HT_PRIME_2, buckets);
	return ((hash_a + (attempt * (hash_b + 1))) % buckets);
}

void ht_insert(t_h_table *ht, const char *key, const char *value)
{
	t_h_item *item;
	t_h_item *cur_item;
	int index;
	int i;
	int load;

	load = ht->count * 100 / ht->size;
	if (load > 70)
		ht_resize_up(ht);
	item = ht_new_item(key, value);
	index = ht_get_hash(item->key, ht->size, 0);
	cur_item = ht->items[index];
	i = 1;
	while (cur_item != NULL)
	{
		index = ht_get_hash(item->key, ht->size, i);
		cur_item = ht->items[index];
		i++;
	}
	ht->items[index] = item;
	ht->count++;
}

char *ht_search(t_h_table *ht, const char *key)
{
	t_h_item *item;
	int index;
	int i;

	index = ht_get_hash(key, ht->size, 0);
	item = ht->items[index];
	i = 1;
	while (item != NULL)
	{
		if (ft_strcmp(item->key, key) == 0)
			return (item->value);
		index = ht_get_hash(key, ht->size, i);
		item = ht->items[index];
		i++;
	}
	return (NULL);
}

// t_h_table			*ht_new(void)
// {
// 	t_h_table		*ht;

// 	ht = malloc(sizeof(t_h_table));
// 	ht->size = 53;
// 	ht->count = 0;
// 	ht->items = calloc((size_t)ht->size, sizeof(t_h_item*));
// 	return (ht);
// }
