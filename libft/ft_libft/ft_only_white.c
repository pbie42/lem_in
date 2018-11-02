/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_white.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:31:57 by pbie              #+#    #+#             */
/*   Updated: 2018/10/30 21:21:50 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool	ft_only_white(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\n')
			;
		else
			return (FALSE);
	}
	return (TRUE);
}