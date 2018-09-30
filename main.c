/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulbie <paulbie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/09/30 14:52:09 by paulbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int main(void)
{
	char *line;
	int lines;
	t_h_table *ht;

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
	ht_free_hash_table(ht);
	printf("Square root ft_floor of %lf is %f\n", 55.0, ft_floor(sqrt(55.0)));
	printf("ft_sqroot ft_floor of %lf is %f\n", 55.0, ft_floor(ft_sqroot(55.0)));
	printf("is 5 prime? %d\n", ft_is_prime(5));
	printf("prime after 6 is? %d\n", ft_next_prime(6));
	return (0);
}
