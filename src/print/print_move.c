/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:47:34 by paul              #+#    #+#             */
/*   Updated: 2018/10/30 16:54:03 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void print_move(int ant_num, char *room_name)
{
	ft_putchar('L');
	ft_putnbr(ant_num);
	ft_putchar('-');
	ft_putstr(room_name);
}