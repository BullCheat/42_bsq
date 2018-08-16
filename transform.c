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

char		read_from_mem(t_coord *c, const t_map *map)
{
	long	base;
	long	std;

	std = sizeof(long) * 8;
	base = ((long*)map->tab)[c->i / std];
	return (char)((base >> (c->i % std)) & 1);
}

char		transform_to(char c, const t_map *map)
{
	if (c == map->empty)
		return (0);
	else if (c == map->obstacle)
		return (1);
	return (ERROR);
}

static char	contains(const t_solution *solution, t_coord *c)
{
	if (solution == (NULL))
		return (0);
	if (c->x >= solution->x && c->x < solution->x + solution->len
		&& c->y >= solution->y && c->y < solution->y + solution->len)
		return (1);
	return (0);
}

char		transform_from(t_coord *c,
				const t_map *map, const t_solution *solution)
{
	long	n;

	if (contains(solution, c))
		return (map->full);
	n = read_from_mem(c, map);
	if (n == 0)
		return (map->empty);
	return (map->obstacle);
}
