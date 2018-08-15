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

#include <time.h>
#include <printf.h>
#include "read_map.h"
#include "solver.h"
#include "print_map.h"
#include "error.h"

int		bsq(int infile)
{
	t_map		*map;

	clock_t start = clock();
	if ((map = read_map(infile)) == NULL)
		return (map_error());
	clock_t read = clock();
	// t_solution *sol = solve_1(map);
	clock_t solve = clock();
	// print_map(map, sol);
	clock_t print = clock();
	printf("\n\n");
	t_solution *sol2 = get_solution();
	// print_map(map, get_solution());
	// printf("sol1 = %d %d %d\n", sol->len, sol->x, sol->y);
	printf("sol2 = %d %d %d\n", sol2->len, sol2->x, sol2->y);
	printf("read  = %lums\nsolve = %lums\nprint = %lums\n", (read - start) * 1000 / CLOCKS_PER_SEC, (solve - read) * 1000 / CLOCKS_PER_SEC, (print - solve) * 1000 / CLOCKS_PER_SEC);
	return (0);
}
