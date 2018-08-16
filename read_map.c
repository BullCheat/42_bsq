/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:46:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 19:34:28 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"

static t_map	*read_meta(int filedes)
{
	int		num_read;
	char	buf[16];
	t_map	*map;

	num_read = 0;
	while (read(filedes, buf + num_read, 1) == 1)
		if (buf[num_read++] == '\n')
			break ;
	if (--num_read < 4)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (map == 0)
		return (NULL);
	map->full = buf[--num_read];
	map->obstacle = buf[--num_read];
	map->empty = buf[--num_read];
	map->height = stol(buf, num_read);
	if (!map->height)
		return (NULL);
	return (map);
}

static char		read_line(const t_map *map, char *buf, t_coord *coord)
{
	char			c;

	coord->x = 0;
	while (coord->x < map->width)
	{
		if ((c = transform_to(buf[coord->x], map)) == ERROR)
		{
			return (0);
		}
		parse(c, coord);
		if (c)
			set(coord, map);
		coord->x++;
		coord->i++;
	}
	if (buf[coord->x] != '\n')
		return (0);
	return (1);
}

static int		fill_map(int filedes, const t_map *map, t_coord *c)
{
	char			*buf;
	unsigned long	temp;
	unsigned long	nread;

	buf = malloc((map->width + 1) * sizeof(char));
	c->y = 1;
	c->i = map->width;
	while (c->y < map->height)
	{
		nread = 0;
		while (nread < map->width)
		{
			temp = (unsigned long)read(filedes,
					buf + nread, map->width + 1 - nread);
			if (temp < 1)
				return (0);
			nread += temp;
		}
		if (!read_line(map, buf, c))
			return (0);
		c->y++;
	}
	if (read(filedes, buf, 1))
		return (0);
	return (1);
}

void			*allocate(unsigned long size)
{
	long			*a;
	unsigned long	i;

	size /= 8;
	a = malloc(size + sizeof(long));
	size /= sizeof(long);
	i = 0;
	while (i <= size)
	{
		a[i++] = 0;
	}
	return (a);
}

t_map			*read_map(int filedes)
{
	t_map	*map;
	t_coord *coord;
	t_llist	*first_line;

	map = read_meta(filedes);
	if (map == NULL)
		return (NULL);
	first_line = read_first_line(filedes, &map->width);
	if (!initialize(map->width))
		return (NULL);
	map->tab = allocate(map->width * map->height);
	if (copy_first_line(first_line, map) == 0)
		return (NULL);
	coord = malloc(sizeof(t_coord));
	if (!fill_map(filedes, map, coord))
		return (NULL);
	free(coord);
	return (map);
}
