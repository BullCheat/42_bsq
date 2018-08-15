/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:55:09 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/14 21:12:49 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "bsq.h"

int		main(int argc, char **argv)
{
	int		infile;
	int		status;
	int		i;

	i = 1;
	status = 0;
	if (argc == 1)
		status = bsq(0);
	else
		while (i < argc)
		{
			infile = open(argv[i++], O_RDONLY);
			if (infile >= 0)
				status = bsq(infile) || status;
			else
				status = 1;// error("cannot open");
			write(1, "\n", 1);
		}
	exit(status);
}
