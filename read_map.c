/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:03:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 15:09:41 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "lib.h"

static map		*read_meta(int filedes)
{
	int		num_read;
	char	buf[16];
	char	*cur_buf;
	map		*map;

	cur_buf = buf;
	while ((num_read = read(filedes, cur_buf, 1)) > 0)
		if (*cur_buf++ == '\n')
			break ;
	//if (num_read == -1)
		//error("read meta map");
	if ((map = malloc(sizeof(map))) == 0)
		/*error("malloc map")*/;
	cur_buf = buf;
	map->height = strptoi(&cur_buf);	
	map->empty = *cur_buf++;
	map->obstacle = *cur_buf++;
	map->full = *cur_buf++;
	return (map);
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	map		*m = read_meta(open(argv[1], O_RDONLY));
	printf("h=%d\n", m->height);
	printf("empty=%d\n", m->empty);
	printf("obstacle=%d\n", m->obstacle);
	printf("full=%d\n", m->full);
	(void)argc;
}

map				*read_map(int filedes)
{
	map		*map;

	map = read_meta(filedes);
	return (map);
}