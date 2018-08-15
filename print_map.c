/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 23:02:25 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 09:41:11 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_map.h"
#include "transform.h"
#include <unistd.h>

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
			char c = transform_from(x++, y, map, solution);
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		y++;
	}
}
