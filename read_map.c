#include "read_map.h"
#include "llist.h"
#include "lib.h"
#include <stdio.h>

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
	//if (num_read == -1)
		//error("read meta map");
	if ((map = malloc(sizeof(t_map))) == 0)
		/*error("malloc map")*/;
	cur_buf = buf;
	map->height = strptoi(&cur_buf);
	map->empty = *cur_buf++;
	map->obstacle = *cur_buf++;
	map->full = *cur_buf++;
	return (map);
}

#define CHUNK_SIZE 50

t_llist			*read_first_line(int filedes, int *len)
{
	int			total_read;
	char		*buf;
	t_llist		*head;
	t_llist		*tail;

	buf = malloc(CHUNK_SIZE);
	total_read = 0;
	head = llist_create_element(buf);
	tail = head;
	while (read(filedes, buf, 1) > 0)
	{
		if (*buf == '\n')
			break ;
		buf++;
		if (++total_read == CHUNK_SIZE)
		{
			buf = malloc(CHUNK_SIZE);
			tail->next = llist_create_element(buf);
			tail = tail->next;
		}
	}
	*len = total_read;
	return (head);
}

void			copy_first_line(t_llist *list, char *buf, int width)
{
	t_llist		*curr;
	int			i;

	i = 0;
	curr = list;
	while (i < width)
	{
		buf[i] = ((char*)curr->data)[i % CHUNK_SIZE];
		if (++i == CHUNK_SIZE)
			curr = curr->next;
	}
}

static char			transform(char c, t_map *map)
{
	if (c == map->empty)
		return (0);
	else if (c == map->obstacle)
		return (1);
	//error
	return (3);
}

t_map			*read_map(int filedes)
{
	t_map	*map;
	t_llist	*first_line;
	char	*buf;
	int		x;
	int		y;
	
	map = read_meta(filedes);
	first_line = read_first_line(filedes, &map->width);
	map->tab = malloc(map->width * map->height * sizeof(char));
	copy_first_line(first_line, map->tab, map->width);
	buf = malloc(map->width * sizeof(char));
	y = 0;
	while (y < map->height && read(filedes, buf, map->width))
	{
		x = 0;
		while (x < map->width)
		{
			map->tab[x + map->width * y] = transform(buf[x], map);
			x++;
		}
		y++;
	}
	return (map);
}
