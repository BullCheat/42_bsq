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

int		bsq(int infile)
{
	t_map		*map;

	if ((map = read_map(infile)) == NULL)
		return (map_error());
	print_map(map, get_solution());
	return (0);
}
