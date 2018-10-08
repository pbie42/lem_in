/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:41 by pbie              #+#    #+#             */
/*   Updated: 2018/10/08 11:45:52 by pbie             ###   ########.fr       */
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
	return (TRUE);
}

void	parse_ants(char *line, t_data *data)
{
	int	ants;

	if (is_ants(line, data))
	{
		ants = ft_atoi(line);
		if (ants <= 0)
			error("ants", data, line);
		data->ants = ants;
		ft_putendlnbr("data->ants ", data->ants);
	}
	else
		error("ants", data, line);
}
