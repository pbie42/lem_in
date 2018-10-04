/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:35:19 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 17:46:22 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	empty_line(char *line)
{
	if (ft_only_white(line))
	{
		free(line);
		ft_exit("Error Occurred: Empty Line Given!");
	}
	free(line);
}

void	error(const char *msg, t_data *data, char *line)
{
	if (!ft_strcmp(msg, "empty"))
		ft_exit("Error Occurred: Empty Map!");
	if (!ft_strcmp(msg, "ants"))
		ft_exit("Error Occurred: No Ants!");
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
