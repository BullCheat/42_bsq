/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:45:15 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 09:37:05 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_line.h"
#include "read_map.h"
#include "transform.h"

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

int			copy_first_line(t_llist *list, t_map *map)
{
	t_llist		*curr;
	int			i;
	char		c;

	i = 0;
	curr = list;
	while (i < map->width)
	{
		if((c = transform_to(((char*)curr->data)[i % CHUNK_SIZE], map)) == ERROR)
			return (0);
		map->tab[i] = c;
		if (++i == CHUNK_SIZE)
			curr = curr->next;
	}
	return (1);
}
