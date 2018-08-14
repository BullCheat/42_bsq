/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:03:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 19:57:30 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "llist.h"
#include "lib.h"

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

#define CHUNK_SIZE 32

t_llist			*read_first_line(int filedes, int *len)
{
	char		*buf;
	int			total_read;
	t_llist		*head;
	t_llist		*tail;

	head = llist_create_element(malloc(CHUNK_SIZE));
	tail = head;
	while (read(filedes, (char*)tail->data, 1) > 0)
	{
		if (*(char*)tail->data == '\n')
			break ;
		if (++total_read == CHUNK_SIZE)
		{
			tail->next = llist_create_element(malloc(CHUNK_SIZE));
			tail = tail->next;
		}
	}
	*len = total_read;
	return (head);
}

void			copy_first_line(t_llist list, char *buf, int width)
{
	t_llist		curr;
	int			i;

	curr = list;
	while (list)
	{
	
	}
}

t_map			*read_map(int filedes)
{
	t_map	*map;
//	int		buf_size;
//	int		num_read;
//	char	*buf;
	t_llist	*first_line;

	map = read_meta(filedes);
	first_line = read_first_line(filedes, &map->width);
	map->tab = malloc(map->width * map->height * sizeof(char));
	copy_first_line(first_line, map->tab, map->width);
	return (map);
}

int main(int argc, char **argv)
{
	map *m = read_map(open(argv[1], O_RDONLY));
	printf("w = %d\t", m->width);
	printf("h = %d\t", m->height);
	printf("empty = %c\t", m->empty);
	printf("obstacle = %c\t", m->obstacle);
	printf("full = %c\n", m->full);
	(void)argc;
}
