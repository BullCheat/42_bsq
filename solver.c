/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrean <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:45:32 by adrean            #+#    #+#             */
/*   Updated: 2018/08/15 16:45:33 by adrean           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "solver.h"

t_solution	*allocate_solution(void)
{
	t_solution *s;

	s = malloc(sizeof(t_solution));
	s->len = 0;
	s->x = 0;
	s->y = 0;
	return (s);
}

t_solution *g_sol;
int g_last_up_left;
int *g_lastrow;

void		initialize(int w)
{
	g_sol = allocate_solution();
	g_lastrow = malloc((w + 1) * sizeof(int));
	memset(g_lastrow, 0, (w + 1) * sizeof(int));
	g_last_up_left = 0;
}

t_solution	*get_solution(void)
{
	free(g_lastrow);
	return (g_sol);
}

void		parse(char c, int x, int y)
{
	int *next;
	int temp2;

	next = g_lastrow + x + 1;
	temp2 = *next;
	if (c)
		*next = 0;
	else
	{
		if (*next > g_lastrow[x])
			*next = g_lastrow[x];
		if (*next > g_last_up_left)
			*next = g_last_up_left;
		*next += 1;
		if (*next > g_sol->len)
		{
			g_sol->len = *next;
			g_sol->x = x - *next + 1;
			g_sol->y = y - *next + 1;
		}
	}
	g_last_up_left = temp2;
}
