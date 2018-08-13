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

static map		read_meta(int filedes)
{
	size_t	num_read;
	char	*buf[16];
	char	*cur_buf;
	map		*map;

	cur_buf = buf;
	while ((num_read = read(filedes, cur_buf, 1)) > 0)
	{
		if (*cur_buf++ == '\n')
			break ;
		cur_buf++;
	}
	if (num_read == -1)
		error("read meta map");
	if ((map = malloc(sizeof(map))) == 0)
		error("malloc map");
	map->height = stsptoi(buf);	
}

map				read_map(int filedes)
{
	
}