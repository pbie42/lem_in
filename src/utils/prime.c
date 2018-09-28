/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 18:45:11 by pbie              #+#    #+#             */
/*   Updated: 2018/09/28 19:51:58 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int is_prime(const int x)
{
	int i;

	if (x < 2)
		return (-1);
	if (x < 4)
		return (1);
	if ((x % 2) == 0)
		return (0);
	i = 3;
	ft_putendl("here");
	while (i < floor(sqroot((double)x)))
	{
		ft_putendl("inside");
		if ((x % i) == 0)
		{
			ft_putendl("returning 0");
			return (0);
		}
		ft_putendl("almost");
		i += 2;
	}
	return (1);
}

int next_prime(int x)
{
	while (is_prime(x) != 1)
		x++;
	return (x);
}
