/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:55:05 by pbie              #+#    #+#             */
/*   Updated: 2018/10/28 16:48:08 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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

int ft_next_prime(int x)
{
	while (ft_is_prime(x) != 1)
		x++;
	return (x);
}
