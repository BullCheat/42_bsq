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

unsigned long	strptol(char **s)
{
	unsigned long n;

	n = 0;
	while (**s >= '0' && **s <= '9')
	{
		n *= 10;
		n += **s - '0';
		(*s)++;
	}
	return (n);
}

void			set(long x, long y, const t_map *map)
{
	long i;
	long id;

	i = (x + y * map->width);
	id = i / sizeof(long); // TODO check perf long char int short
	((long *)map->tab)[id] |= 1 << (i % sizeof(long));
}
