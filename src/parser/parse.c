/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:36:30 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 15:26:35 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_bool	validate_parse(t_parse *p)
{
	if (p->start_found && p->end_found && p->rooms_done && p->links_done)
		return (TRUE);
	return (FALSE);
}

static t_parse	*setup_parse(void)
{
	t_parse *p;

	p = NULL;
	p = malloc(sizeof(t_parse));
	p->lines = 0;
	p->rooms_done = FALSE;
	p->links_done = FALSE;
	p->start_found = FALSE;
	p->end_found = FALSE;
	return (p);
}

void		parse(t_data *data)
{
	t_parse		*p;

	p = NULL;
	p = setup_parse();
	while (ft_get_next_line(0, &p->line) == 1)
	{
		ft_putendl(p->line);
		// if (p->line[0] == '\n' || p->line[0] == ' ')
		// 	error("newline", data);
		if (p->lines == 0)
			parse_ants(p->line, data);
		else if (is_command(p->line))
			set_found_command(p);
		else if (is_comment(p->line))
			;
		else if (!p->rooms_done && !p->links_done && is_room(p->line))
			ft_putendl("It's a ROOM!!");
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
	if (validate_parse(p))
		ft_putendl("VALID PARSE!");
}
