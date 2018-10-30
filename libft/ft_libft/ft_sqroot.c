/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqroot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:05:32 by pbie              #+#    #+#             */
/*   Updated: 2018/10/30 21:22:04 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

double	ft_sqroot(double square)
{
	double root;
	double last;
	double diff;

	root = square / 3;
	diff = 1;
	if (square <= 0)
		return (0);
	last = root;
	root = (root + square / root) / 2;
	diff = root - last;
	while (diff > MINDIFF || diff < -MINDIFF)
	{
		last = root;
		root = (root + square / root) / 2;
		diff = root - last;
	}
	return (root);
}
