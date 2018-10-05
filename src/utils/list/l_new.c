/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:21:29 by pbie              #+#    #+#             */
/*   Updated: 2018/10/05 16:21:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_link		*l_new(char *key)
{
	t_link	*new_link;

	new_link = (t_link*)malloc(sizeof(t_link));
	new_link->key = ft_strdup(key);
	new_link->next = NULL;
	return (new_link);
}
