/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:36:30 by pbie              #+#    #+#             */
/*   Updated: 2018/11/01 13:46:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	validate_parse(t_parse *p, t_data *data)
{
	if (!p->rooms_done)
		error("room", data, p->line);
	if (p->start_found && !data->start)
		error("startroom", data, p->line);
	if (p->end_found && !data->end)
		error("endroom", data, p->line);
	if (p->start_found && p->end_found && p->rooms_done)
		return (TRUE);
	return (FALSE);
}

static t_parse	*setup_parse(void)
{
	t_parse		*p;

	p = NULL;
	p = malloc(sizeof(t_parse));
	p->lines = 0;
	p->rooms = 0;
	p->rooms_done = FALSE;
	p->ants_done = FALSE;
	p->start_found = FALSE;
	p->end_found = FALSE;
	return (p);
}

static void		parse_room_link(t_parse *p, t_data *data)
{
	if (!p->ants_done)
		error("ants", data, p->line);
	if (!p->rooms_done && is_link(p->line))
		p->rooms_done = TRUE;
	if (p->rooms_done)
	{
		if (!p->start_found)
			error("start", data, p->line);
		if (!p->end_found)
			error("end", data, p->line);
		if (p->rooms_done && p->rooms == 0)
			error("rooms", data, p->line);
		if (!is_link(p->line))
			error("link", data, p->line);
		link_parse(p, data);
	}
	if (!p->rooms_done && !is_room(p->line))
		error("room", data, p->line);
	if (!p->rooms_done)
		room_parse(p, data);
}

void			parse(t_data *data)
{
	t_parse		*p;

	p = setup_parse();
	while (ft_get_next_line(0, &p->line) == 1)
	{
		ft_putendl(p->line);
		if (is_command(p->line))
			set_found_command(p);
		else if (is_comment(p->line))
			;
		else if (!p->ants_done)
		{
			p->ants_done = TRUE;
			parse_ants(p->line, data);
		}
		else
			parse_room_link(p, data);
		free(p->line);
		p->lines++;
	}
	if (p->lines <= 0)
		error("empty", data, NULL);
	validate_parse(p, data);
	free(p->line);
	free(p);
}
