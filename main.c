/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:55:09 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/08 20:05:33 by adrean           ###   ########.fr       */
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
			close(infile);
			if (i == argc - 1 && argc > 2)
				write(1, "\n", 1);
		}
	return (0);
}
