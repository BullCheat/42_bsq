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

char			readmap(long x, long y, t_map *map)
{
	long i;

	i = (x + y * map->width);
	return ((map->tab[i >> 3] >> (i & 7)) & 1);
}

char			transform_to(char c, t_map *map)
{
	if (c == map->empty)
		return (0);
	else if (c == map->obstacle)
		return (1);
	return (ERROR);
}

static char		contains(t_solution *solution, long x, long y)
{
	if (solution == (NULL))
		return (0);
	if (x >= solution->x && x < solution->x + solution->len
		&& y >= solution->y && y < solution->y + solution->len)
		return (1);
	return (0);
}

char			transform_from(long x, long y, t_map *map, t_solution *solution)
{
	long	n;

	if (contains(solution, x, y))
		return (map->full);
	n = readmap(x, y, map);
	if (n == 0)
		return (map->empty);
	return (map->obstacle);
}
