/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:40 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 17:39:05 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool	is_room(const char *line)
{
	char	**room;

	if (line[0] == 'L')
		return (FALSE);
	if (ft_wordcount(line, ' ') != 3)
		return (FALSE);
	room = ft_strsplit(line, ' ');
	if (!ft_is_pos_num(room[1]))
	{
		ft_free_matrix(room);
		return (FALSE);
	}
	if (!ft_is_pos_num(room[2]))
	{
		ft_free_matrix(room);
		return (FALSE);
	}
	ft_free_matrix(room);
	return (TRUE);
}

void	parse_room(char *line, t_data *data)
{
}
