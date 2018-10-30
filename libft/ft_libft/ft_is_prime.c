/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:34:19 by paul              #+#    #+#             */
/*   Updated: 2018/10/30 21:34:39 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_is_prime(const int x)
{
	int i;

	if (x < 2)
		return (-1);
	if (x < 4)
		return (1);
	if ((x % 2) == 0)
		return (0);
	i = 3;
	while (i < ft_floor(ft_sqroot((double)x)))
	{
		if ((x % i) == 0)
			return (0);
		i += 2;
	}
	return (1);
}