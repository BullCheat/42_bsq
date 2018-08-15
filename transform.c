/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:33:06 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 11:28:03 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

char			transform_to(char c, t_map *map)
{
	if (c == map->empty)
		return (0);
	else if (c == map->obstacle)
		return (1);
	return (ERROR);
}

static char		contains(t_solution *solution, int x, int y)
{
	if (solution == (NULL))
		return (0);
	if (x >= solution->x && x < solution->x + solution->len
		&& y >= solution->y && y < solution->y + solution->len)
		return (1);
	return (0);
}

char			transform_from(int x, int y, t_map *map, t_solution *solution)
{
	int		n;

	if (contains(solution, x, y))
		return (map->full);
	n = map->tab[x + map->width * y] & 1;
	if (n == 0)
		return (map->empty);
	return (map->obstacle);
}
