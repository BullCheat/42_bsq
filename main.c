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

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "error.h"
#include "bsq.h"

int		main(int argc, char **argv)
{
	int		infile;
	int		status;
	int		i;

	i = 1;
	status = 0;
	if (argc == 1)
	{
		status = bsq(0);
		write(1, "\n", 1);
	}
	else
		while (i < argc)
		{
			infile = open(argv[i++], O_RDONLY);
			if (infile >= 0)
				status = bsq(infile) || status;
			else
			{
				error("cannot open", 13);
				status = 1;
			}
			if (i != argc)
				write(1, "\n", 1);
		}
	exit(status);
}
