/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:35:19 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 16:00:19 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	error(const char *msg, t_data *data)
{
	if (!ft_strcmp(msg, "empty"))
		ft_exit("Error Occurred: Empty Map!");
	if (!ft_strcmp(msg, "ants"))
		ft_exit("Error Occurred: No Ants!");
	if (!ft_strcmp(msg, "newline"))
	{
		// Will need to figure out memory freeing at this point
		ft_exit("Error Occurred: Empty Line Given!");
	}
	if (!ft_strcmp(msg, "room"))
	{
		// Will need to figure out memory freeing at this point
		ft_exit("Error Occurred: Invalid Room Given!");
	}
	if (!ft_strcmp(msg, "link"))
	{
		// Will need to figure out memory freeing at this point
		ft_exit("Error Occurred: Invalid Link Given!");
	}
	if (data && data->start != NULL){
		free(data->start);
		ft_putendl("freed start");
	}
	if (data && data->end != NULL) {
		free(data->end);
		ft_putendl("freed end");
	}
	if (data && data->map) {
		ht_free_hash_table(data->map);
		ft_putendl("freed table");
	}
	ft_putstr("Error Occurred: ");
	ft_putstr(msg);
	ft_exit("!");
}
