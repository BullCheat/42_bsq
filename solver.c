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
	unsigned long	i;
	size_t			l;

	if (w < 1)
		return (0);
	g_sol = allocate_solution();
	l = (w + 1) * sizeof(LAST_ROW_TYPE) + sizeof(long);
	g_lastrow = malloc(l);
	i = 0;
	while (i < l / sizeof(long))
		((long*)g_lastrow)[i++] = 0;
	g_last_up_left = 0;
	return (1);
}

t_solution	*get_solution(void)
{
	free(g_lastrow);
	return (g_sol);
}

void		parse(char c, t_coord *coord)
{
	LAST_ROW_TYPE *next;
	LAST_ROW_TYPE temp2;

	next = g_lastrow + coord->x + 1;
	temp2 = *next;
	if (c)
		*next = 0;
	else
	{
		if (*next > g_lastrow[coord->x])
			*next = g_lastrow[coord->x];
		if (*next > g_last_up_left)
			*next = g_last_up_left;
		*next += 1;
		if (*next > g_sol->len)
		{
			g_sol->len = *next;
			g_sol->x = (unsigned long)(coord->x - *next + 1);
			g_sol->y = (unsigned long)(coord->y - *next + 1);
		}
	}
	g_last_up_left = temp2;
}
