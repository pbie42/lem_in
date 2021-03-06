/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:20:31 by pbie              #+#    #+#             */
/*   Updated: 2018/10/30 21:21:42 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool		ft_is_num(const char *string)
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
