/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:35:19 by pbie              #+#    #+#             */
/*   Updated: 2018/10/28 18:05:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void path_error(const char *msg, t_data *data, t_bfs *bfs)
{
	if (!ft_strcmp(msg, "end"))
		ft_exit("Error Occured: No path from start to end rooms");
}

void empty_line(char *line)
{
	if (ft_only_white(line))
	{
		ft_putendl("about to free line only white");
		free(line);
		ft_exit("Error Occurred: Empty Line Given!");
	}
	ft_putendl("about to free line empy line");
	free(line);
}

void error(const char *msg, t_data *data, char *line)
{
	ft_putendl("in error");
	if (!ft_strcmp(msg, "empty"))
		ft_exit("Error Occurred: Empty Map!");
	if (!ft_strcmp(msg, "ants"))
		ft_exit("Error Occurred: Not Enough Ants!");
	if (!ft_strcmp(msg, "start"))
		ft_exit("Error Occurred: No Start Command!");
	if (!ft_strcmp(msg, "startroom"))
		ft_exit("Error Occurred: No Start Room Given!");
	if (!ft_strcmp(msg, "end"))
		ft_exit("Error Occurred: No End Command!");
	if (!ft_strcmp(msg, "endroom"))
		ft_exit("Error Occurred: No End Room Given!");
	if (!ft_strcmp(msg, "rooms"))
		ft_exit("Error Occurred: No Rooms Given!");
	if (!ft_strcmp(msg, "room"))
	{
		empty_line(line);
		ft_exit("Error Occurred: Invalid Room Given!");
	}
	if (!ft_strcmp(msg, "link"))
	{
		empty_line(line);
		ft_exit("Error Occurred: Invalid Link Given!");
	}
}
