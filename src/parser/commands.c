/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:21:57 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 14:08:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool	is_command(const char *line)
{
	if (line[0] && line[0] == '#' && line[1] && line[1] == '#')
		return (TRUE);
	return (FALSE);
}

void		set_found_command(t_parse *p)
{
	if (!p->start_found && !ft_strcmp(p->line, "##start"))
		p->start_found = TRUE;
	if (!p->end_found && !ft_strcmp(p->line, "##end"))
		p->end_found = TRUE;
}
