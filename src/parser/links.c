/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:35:37 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 16:22:49 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_bool		is_link(char* line)
{
	if (line[0] == 'L')
		return (FALSE);
	if (ft_wordcount(line, '-') != 2)
		return (FALSE);
	if (ft_check_white(line))
		return (FALSE);
	return (TRUE);
}
