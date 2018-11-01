/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:15:45 by pbie              #+#    #+#             */
/*   Updated: 2018/11/01 17:42:35 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		paths_len(t_qv *path)
{
	t_qv		*tmp;
	int		len;

	tmp = path;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int		cnt_set_lens(t_paths *paths)
{
	t_paths	*tmp;
	int		cnt;

	tmp = paths;
	cnt = 0;
	while (tmp)
	{
		cnt++;
		tmp->len = paths_len(tmp->path);
		tmp = tmp->next;
	}
	return (cnt);
}

int		shortest_len(t_paths *paths)
{
	t_paths	*tmp_paths;
	int shortest;

	tmp_paths = paths;
	shortest = 0;
	while (tmp_paths)
	{
		if (shortest == 0 || tmp_paths->len < shortest)
			shortest = tmp_paths->len;
		tmp_paths = tmp_paths->next;
	}
	return (shortest);
}

int		longest_len(t_paths *paths)
{
	t_paths	*tmp_paths;
	int longest;

	tmp_paths = paths;
	longest = 0;
	while (tmp_paths)
	{
		if (longest == 0 || tmp_paths->len > longest)
			longest = tmp_paths->len;
		tmp_paths = tmp_paths->next;
	}
	return (longest);
}
