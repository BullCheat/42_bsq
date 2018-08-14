/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 23:02:25 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 23:47:49 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_map.h"
#include <unistd.h>

static char		contains(t_solution *solution, int x, int y)
{
	if (solution == (NULL))
		return (0);
	if (x >= solution->x && x < solution->x + solution->len
		&& y >= solution->y && y < solution->y + solution->len)
		return (1);
	return (0);
}

static char		transform(int x, int y, t_map *map, t_solution *solution)
{
	int		n;

	if (contains(solution, x, y))
		return (map->full);
	n = map->tab[x + map->width * y] & 1;
	if (n == 0)
		return (map->empty);
	return (map->obstacle);
}

void			print_map(t_map *map, t_solution *solution)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			char c = transform(x++, y, map, solution);
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		y++;
	}
}
