/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 23:02:25 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 16:17:09 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_map.h"
#include "transform.h"
#include <unistd.h>

void			try_flush_buf(char *buf, unsigned long *len)
{
	if (*len == BUF_SIZE)
	{
		write(1, buf, *len);
		*len = 0;
	}
}

void			print_map(const t_map *map, const t_solution *solution)
{
	char			buf[BUF_SIZE];
	t_coord			*c;
	unsigned long	i;

	c = malloc(sizeof(t_coord));
	c->y = 0;
	c->i = 0;
	i = 0;
	while (c->y < map->height)
	{
		c->x = 0;
		while (c->x < map->width)
		{
			try_flush_buf(buf, &i);
			buf[i++] = transform_from(c, map, solution);
			c->x++;
			c->i++;
		}
		try_flush_buf(buf, &i);
		buf[i++] = '\n';
		c->y++;
	}
	free(c);
	if (i > 0)
		write(1, buf, i);
}
