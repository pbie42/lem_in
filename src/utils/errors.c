/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:35:19 by pbie              #+#    #+#             */
/*   Updated: 2018/11/02 20:21:39 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	path_error(const char *msg, t_data *data, t_bfs *bfs)
{
	if (!ft_strcmp(msg, "end"))
		ft_exit("ERROR Occured: No path from start to end rooms");
}

void	empty_line(char *line)
{
	if (ft_only_white(line))
	{
		free(line);
		ft_exit("ERROR Occurred: Empty Line Given!");
	}
	free(line);
}

void	error(const char *msg, t_data *data, char *line)
{
	if (!ft_strcmp(msg, "empty"))
		ft_exit("ERROR Occurred: Empty Map!");
	if (!ft_strcmp(msg, "ants"))
		ft_exit("ERROR Occurred: Not Enough Ants!");
	if (!ft_strcmp(msg, "start"))
		ft_exit("ERROR Occurred: No Start Command!");
	if (!ft_strcmp(msg, "startroom"))
		ft_exit("ERROR Occurred: No Start Room Given!");
	if (!ft_strcmp(msg, "end"))
		ft_exit("ERROR Occurred: No End Command!");
	if (!ft_strcmp(msg, "endroom"))
		ft_exit("ERROR Occurred: No End Room Given!");
	if (!ft_strcmp(msg, "rooms"))
		ft_exit("ERROR Occurred: No Rooms Given!");
	if (!ft_strcmp(msg, "room"))
	{
		empty_line(line);
		ft_exit("ERROR Occurred: Invalid Room Given!");
	}
	if (!ft_strcmp(msg, "link"))
	{
		empty_line(line);
		ft_exit("ERROR Occurred: Invalid Link Given!");
	}
}
