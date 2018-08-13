/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:55:09 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 12:18:49 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		infile;
	int		status;
	int		i;

	i = 1;
	if (argc == 1)
		status = bsq(0);
	else
		while (i < argc)
			if((infile = open(argv[i++])) == -1)
				status = error("cannot open");
			else
				status = bsq(infile) || status;
	exit(status);
}
