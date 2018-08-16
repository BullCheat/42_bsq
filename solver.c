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
LAST_ROW_TYPE g_last_up_left;
LAST_ROW_TYPE *g_lastrow;

char		initialize(size_t w)
{
	if (w < 1)
		return (0);
	g_sol = allocate_solution();
	g_lastrow = malloc((w + 1) * sizeof(LAST_ROW_TYPE));
	memset(g_lastrow, 0, (w + 1) * sizeof(LAST_ROW_TYPE));
	g_last_up_left = 0;
	return (1);
}

t_solution	*get_solution(void)
{
	free(g_lastrow);
	return (g_sol);
}

void		parse(char c, long x, long y)
{
	LAST_ROW_TYPE *next;
	LAST_ROW_TYPE temp2;

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
			g_sol->x = (unsigned long)(x - *next + 1);
			g_sol->y = (unsigned long)(y - *next + 1);
		}
	}
	g_last_up_left = temp2;
}
