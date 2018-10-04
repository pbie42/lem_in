/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:36:30 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 17:15:21 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_bool	validate_parse(t_parse *p)
{
	if (p->start_found && p->end_found && p->rooms_done)
		return (TRUE);
	ft_putendlnbr("p->start_found ", p->start_found);
	ft_putendlnbr("p->end_found ", p->end_found);
	ft_putendlnbr("p->rooms_done ", p->rooms_done);
	return (FALSE);
}

static t_parse	*setup_parse(void)
{
	t_parse *p;

	p = NULL;
	p = malloc(sizeof(t_parse));
	p->lines = 0;
	p->rooms = 0;
	p->rooms_done = FALSE;
	p->start_found = FALSE;
	p->end_found = FALSE;
	return (p);
}

static void		parse_room_link(t_parse *p, t_data *data)
{
	if (!p->rooms_done && is_link(p->line))
		p->rooms_done = TRUE;
	if (p->rooms_done)
	{
		if (!is_link(p->line))
			error("link", data, p->line);
		ft_putendl("It's a LINK!!");
	}
	if (!p->rooms_done && !is_room(p->line))
		error("room", data, p->line);
	if (!p->rooms_done)
		ft_putendl("It's a ROOM!!");
}

void		parse(t_data *data)
{
	t_parse		*p;

	p = NULL;
	p = setup_parse();
	while (ft_get_next_line(0, &p->line) == 1)
	{
		ft_putendl(p->line);
		if (p->lines == 0)
			parse_ants(p->line, data);
		else if (is_command(p->line))
			set_found_command(p);
		else if (is_comment(p->line))
			;
		else
			parse_room_link(p, data);
		free(p->line);
		p->lines++;
	}
	free(p->line);
	if (p->lines <= 0)
		error("empty", data, NULL);
	ft_putendl("yeahh boiiii");
	if (validate_parse(p))
		ft_putendl("VALID PARSE!");
	free(p);
}
