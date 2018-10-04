/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:21:57 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 13:53:00 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool	is_valid_command(const char *line)
{
	if (line[0] && line[0] == '#' && line[1] && line[1] == '#')
	{
		if (ft_strcmp(line, "##start") || ft_strcmp(line, "##end"))
			return (TRUE);
		return (FALSE);
	}
	return (FALSE);
}
