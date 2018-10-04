/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:41 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 11:09:58 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool	is_ants(char *line, t_data *data)
{
	int i;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (FALSE);
	data->ants = ft_atoi(line);
	return (TRUE);
}

void	parse_ants(char *line, t_data *data)
{
	if (is_ants(line, data))
	{
		ft_putendl("it's ants bruh");
		ft_putendlnbr("data->ants ", data->ants);
	}
	else
		ft_exit("Invalid ants input!");
}
