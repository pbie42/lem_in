/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:21:25 by pbie              #+#    #+#             */
/*   Updated: 2018/10/04 19:31:39 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	if (!s || !c)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char		**ft_create_line(const char *s, char **arr, char c, int count)
{
	int		i;
	int		k;
	size_t	start;
	size_t	length;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c && count-- > 0)
		{
			start = i;
			length = 0;
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
				length++;
			}
			arr[k] = ft_strsub(s, start, length);
			k++;
		}
		if (s[i])
			i++;
	}
	return (arr);
}

char			**ft_strsplit(const char *s, char c)
{
	int		amt;
	char	**arr;

	amt = 0;
	arr = NULL;
	if (!s)
		return (NULL);
	amt = ft_count_words(s, c);
	if (amt <= 0)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (amt + 1))))
		return (NULL);
	arr = ft_create_line(s, arr, c, amt);
	arr[amt] = NULL;
	return (arr);
}
