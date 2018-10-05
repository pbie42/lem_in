/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pos_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:10:30 by pbie              #+#    #+#             */
/*   Updated: 2018/10/05 16:16:18 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool		ft_is_pos_num(const char *string)
{
	int		i;

	i = -1;
	if (string[0] == '-' && string[1] && ft_isdigit(string[1]))
		i++;
	while (string[++i])
		if (!ft_isdigit(string[i]))
			return (FALSE);
	return (TRUE);
}
