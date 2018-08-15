#include "read_map.h"
#include "first_line.h"
#include "llist.h"
#include "lib.h"
#include <stdio.h>
#include "error.h"

static t_map	*read_meta(int filedes)
{
	int		num_read;
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

#define ERROR 127
char			transform(char c, t_map *map)
{
	if (c == map->empty)
		return (0);
	else if (c == map->obstacle)
		return (1);
	//error
	return (ERROR);
}


t_map			*read_map(int filedes)
{
	t_map	*map;
	t_llist	*first_line;
	char	*buf;
	int		x;
	int		y;
	char	c;

	map = read_meta(filedes);
	first_line = read_first_line(filedes, &map->width);
	map->tab = malloc(map->width * map->height * sizeof(char));
	if (copy_first_line(first_line, map) == 0)
		return (NULL);
	buf = malloc((map->width + 1) * sizeof(char));
	y = 0;
	while (y < map->height - 1 && read(filedes, buf, map->width + 1) > 0)
	{
		x = 0;
		while (x < map->width)
		{
			c = transform(buf[x], map);
			if (c == ERROR)
				return (NULL);
			map->tab[x + map->width * (1+y)] = c;
			x++;
		}
		if (buf[x] != '\n')
			return (NULL);
		y++;
	}
	if (y < map->height - 1)
		return (NULL);
	if (read(filedes, buf, 1) != 0)
		return (NULL);
	return (map);
}
