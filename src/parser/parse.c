/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:36:30 by pbie              #+#    #+#             */
/*   Updated: 2018/09/30 19:31:06 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void parse(t_data *data)
{
	char *line;
	int lines;
	t_bool rooms_done;
	t_bool links;

	lines = 0;
	rooms_done = FALSE;
	links = FALSE;
	while (ft_get_next_line(0, &line) == 1)
	{
		ft_putendl(line);
		if (lines == 0)
			parse_ants(line, data);
		if (!rooms_done && is_room(line))
			parse_room(line, data);
		else
		{
			rooms_done = TRUE;
		}
		free(line);
		lines++;
	}
	free(line);
	if (lines <= 0)
		error();
	else
		ft_putendl("yeahh boiiii");
}
