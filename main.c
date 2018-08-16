/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:55:09 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 15:38:35 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "error.h"
#include "bsq.h"

int		main(int argc, char **argv)
{
	int		infile;
	int		i;

	i = 1;
	if (argc == 1)
	{
		bsq(0);
	}
	else
		while (i < argc)
		{
			infile = open(argv[i++], O_RDONLY);
			if (infile >= 0)
				bsq(infile);
			else
				map_error();
		}
	/*t_map *m = malloc(sizeof(t_map));
	m->obstacle = 'o';
	m->empty = '.';
	m->full = 'x';
	m->height = 100;
	m->width = 100;
	m->tab = allocate(m->height * m->width);
	set(34, 27, m);
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (read_from_mem(i, j, m) && (i != 34 || j != 27))
				break;
		}
	}*/
	return (0);
}
