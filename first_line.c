/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:45:15 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 16:13:42 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_line.h"

t_llist			*read_first_line(int filedes, unsigned long *len)
{
	unsigned long	total_read;
	char			*buf;
	t_llist			*head;
	t_llist			*tail;

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

t_llist			*next(t_llist **old)
{
	t_llist *temp;

	temp = (*old)->next;
	free(*old);
	*old = temp;
}

int				copy_first_line(t_llist *curr, const t_map *map)
{
	char			c;
	t_coord			*coord;

	coord = malloc(sizeof(t_coord));
	coord->i = 0;
	coord->x = 0;
	coord->y = 0;
	while (coord->i < map->width)
	{
		c = transform_to(((char*)curr->data)[coord->i % CHUNK_SIZE], map);
		if (c == ERROR)
			return (0);
		parse(c, coord);
		if (c)
			set(coord, map);
		coord->i++;
		coord->x++;
		if (coord->i == CHUNK_SIZE)
			next(&curr);
	}
	if (curr != NULL)
		free(curr);
	return (1);
}
