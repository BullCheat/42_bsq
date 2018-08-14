/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:06:29 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 23:43:23 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "solver.h"
#include "print_map.h"

int		bsq(int infile)
{
	t_map		*map;

	map = read_map(infile);
	print_map(map, solve(map));
	return (0);
}
