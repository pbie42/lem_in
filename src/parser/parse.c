/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:36:30 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 14:19:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		parse(t_data *data)
{
	t_parse		*p;

	p = NULL;
	p = malloc(sizeof(t_parse));
	p->lines = 0;
	p->rooms_done = FALSE;
	p->links = FALSE;
	p->start_found = FALSE;
	p->end_found = FALSE;
	while (ft_get_next_line(0, &p->line) == 1)
	{
		ft_putendl(p->line);
		if (p->lines == 0)
			parse_ants(p->line, data);
		else if (is_command(p->line))
			set_found_command(p);
		else if (is_comment(p->line))
			;
		// else if (!p->rooms_done && is_room(p->line))
		// 	parse_room(p->line, data);
		else
		{
			p->rooms_done = TRUE;
		}
		free(p->line);
		p->lines++;
	}
	free(p->line);
	if (p->lines <= 0)
		error("empty", data);
	else
		ft_putendl("yeahh boiiii");
}
