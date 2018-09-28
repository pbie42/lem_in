/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:50:19 by pbie              #+#    #+#             */
/*   Updated: 2018/09/28 18:36:59 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_h_item	*ht_new_item(const char *k, const char *v)
{
	t_h_item			*item;

	item = malloc(sizeof(t_h_item));
	item->key = ft_strdup(k);
	item->value = ft_strdup(v);
	return (item);
}

t_h_table			*ht_new(void)
{
	t_h_table		*ht;

	ht = malloc(sizeof(t_h_table));
	ht->size = 53;
	ht->count = 0;
	ht->items = calloc((size_t)ht->size, sizeof(t_h_item*));
	return (ht);
}

static void			ht_del_item(t_h_item *i)
{
	free(i->key);
	free(i->value);
	free(i);
}

void					ht_del_hash_table(t_h_table *ht)
{
	int				i;
	t_h_item			*item;

	i = 0;
	
	while(i < ht->size){
		item = ht->items[i];
		if (item != NULL)
			ht_del_item(item);
		i++;
	}
	free(ht->items);
	free(ht);
}

static int			ht_hash(const char *s, const int a, const int m)
{
	long				hash;
	int		len_s;
	int				i;

	hash = 0;
	len_s = ft_strlen(s);
	i = 0;
	while (i < len_s)
	{
		hash += x_to_the_n(a, len_s - (i + 1)) * s[i];
		hash = hash % m;
	}
	return ((int)hash);
}

static int			ht_get_hash(const char *s, const int buckets, const int attempt)
{
	int				hash_a;
	int				hash_b;

	hash_a = ht_hash(s, HT_PRIME_1, buckets);
	hash_b = ht_hash(s, HT_PRIME_2, buckets);
	return ((hash_a + (attempt* (hash_b + 1))) % buckets);
}

void					ht_insert(t_h_table *ht, const char *key, const char *value)
{
	t_h_item			*item;
	t_h_item			*cur_item;
	int				index;
	int				i;

	item = ht_new_item(key, value);
	index = ht_get_hash(item->key, ht->size, 0);
	cur_item = ht->items[index];
	i = 1;
	while(cur_item != NULL)
	{
		index = ht_get_hash(item->key, ht->size, i);
		cur_item = ht->items[index];
		i++;
	}
	ht->items[index] = item;
	ht->count++;
}

char					*ht_search(t_h_table *ht, const char *key)
{
	t_h_item			*item;
	int				index;
	int				i;

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
