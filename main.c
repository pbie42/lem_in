/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/09/28 19:53:58 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int main(void)
{
	char			*line;
	int			lines;
	t_h_table	*ht;

	while (ft_get_next_line(0, &line) == 1)
	{
		ft_putendl(line);
		lines++;
	}
	if (lines <= 0)
		error();
	else
		ft_putendl("yeahh boiiii");

	ht = ht_new();
	ht_del_hash_table(ht);
	printf("Square root floor of %lf is %f\n", 55.0, floor(sqrt(55.0)) );
	printf("sqroot floor of %lf is %f\n", 55.0, floor(sqroot(55.0)) );
	printf("is 5 prime? %d\n", is_prime(5));
	printf("prime after 6 is? %d\n", next_prime(6));
	return (0);
}
