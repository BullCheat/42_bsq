/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:33:06 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 16:51:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

char		read_from_mem(long x, long y, const t_map *map)
{
	long			i;
	unsigned long	base;

	i = (x + y * map->width);
	base = ((unsigned long*)map->tab)[i / sizeof(long)];
	return (char)((base >> (i % sizeof(long))) & 1);
}

char		transform_to(char c, const t_map *map)
{
	if (c == map->empty)
		return (0);
	else if (c == map->obstacle)
		return (1);
	return (ERROR);
}

static char	contains(const t_solution *solution, ULONG x, ULONG y)
{
	if (solution == (NULL))
		return (0);
	if (x >= solution->x && x < solution->x + solution->len
		&& y >= solution->y && y < solution->y + solution->len)
		return (1);
	return (0);
}

char		transform_from(ULONG x, ULONG y,
				const t_map *map, const t_solution *solution)
{
	long	n;

	if (contains(solution, x, y))
		return (map->full);
	n = read_from_mem(x, y, map);
	if (n == 0)
		return (map->empty);
	return (map->obstacle);
}
