/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:40 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 15:19:01 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		ft_free_matrix(char **matrix)
{
	int i;

	i = -1;
	while(matrix[++i])
		free(matrix[i]);
	free(matrix);
}

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
