/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:44:47 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 12:18:51 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

unsigned long	stol(char *s, int num)
{
	unsigned long	n;
	int				i;

	n = 0;
	i = 0;
	while (i < num)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		n *= 10;
		n += s[i] - '0';
		i++;
	}
	return (n);
}

void			set(t_coord *c, const t_map *map)
{
	long std;

	std = sizeof(long) * 8;
	((long *)map->tab)[c->i / std] |= 1L << (c->i % std);
}
