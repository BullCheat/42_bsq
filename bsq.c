/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:06:29 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 10:34:56 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "solver.h"
#include "print_map.h"
#include "error.h"

void	bsq(int infile)
{
	t_map	*map;

	map = read_map(infile);
	if (map != NULL)
		print_map(map, get_solution());
	else
		map_error();
}
