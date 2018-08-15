/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:46:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 16:48:22 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "first_line.h"
#include "lib.h"
#include "transform.h"
#include "error.h"
#include "solver.h"

void			set(long x, long y, t_map *map)
{
	long i;
	long id;

	i = (x + y * map->width);
	id = i >> 3;
	map->tab[id] |= map->tab[id] | 1 << (i & 7);
}

static t_map	*read_meta(int filedes)
{
	long	num_read;
	char	buf[16];
	char	*cur_buf;
	t_map	*map;

	cur_buf = buf;
	while ((num_read = read(filedes, cur_buf, 1)) > 0)
		if (*cur_buf++ == '\n')
			break ;
	if (num_read == -1)
		error("read meta map", 14);
	if ((map = malloc(sizeof(t_map))) == 0)
		error("malloc map", 10);
	cur_buf = buf;
	map->height = strptoi(&cur_buf);
	map->empty = *cur_buf++;
	map->obstacle = *cur_buf++;
	map->full = *cur_buf++;
	return (map);
}

static int		fill_map(int filedes, t_map *map)
{
	long	x;
	long	y;
	char	c;
	char	*buf;
	int		temp;

	buf = malloc((map->width + 1) * sizeof(char));
	y = 1;
	while (y < map->height)
	{
		temp = read(filedes, buf, map->width + 1);
		if (temp == 0)
		{
			write(2, "Error\n", 6);
			break ;
		}
		while (temp < map->width)
		{
			temp += read(filedes, buf + temp, map->width + 1 - temp);
		}
		x = 0;
		while (x < map->width)
		{
			if ((c = transform_to(buf[x], map)) == ERROR)
			{
				write(2, buf, temp);
				write(2, "\n", 1);
				return (0);
			}
			parse(c, x, y);
			if (c)
				set(x, y, map);
			x++;
		}
		if (buf[x] != '\n')
		{
			return (0);
		}
		y++;
	}
	if (y < map->height)
		return (0);
	if (read(filedes, buf, 1) != 0)
		return (0);
	return (1);
}

void			*allocate(long size)
{
	long	*a;
	int		i;

	a = malloc(size + sizeof(long));
	size /= sizeof(long);
	i = 0;
	while (i < size + 1)
	{
		a[i++] = 0;
	}
	return (a);
}

t_map			*read_map(int filedes)
{
	t_map	*map;
	t_llist	*first_line;

	map = read_meta(filedes);
	first_line = read_first_line(filedes, &map->width);
	initialize(map->width);
	map->tab = allocate(map->width * map->height);
	if (copy_first_line(first_line, map) == 0)
		return (NULL);
	if (fill_map(filedes, map) == 0)
		return (NULL);
	return (map);
}
