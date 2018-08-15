// FIXME header

#include <string.h>
#include "solver.h"

t_solution *allocate_solution() {
	t_solution *s = malloc(sizeof(t_solution));
	s->len = 0;
	s->x = 0;
	s->y = 0;
	return s;
}

t_solution *sol;
int last_up_left;
int *r;

void initialize(int w) {
	sol = allocate_solution();
	r = malloc((w+1) * sizeof(int));
	memset(r, 0, (w+1) * sizeof(int));
	last_up_left = 0;
}

t_solution *get_solution() {
	free(r);
	return sol;
}

void parse(char c, int x, int y) {
	int *next = r + x + 1;
	int temp2 = *next;
	if (c)
		*next = 0;
	else
	{
		if (*next > r[x])
			*next = r[x];
		if (*next > last_up_left)
			*next = last_up_left;
		*next += 1;
		if (*next > sol->len) {
			sol->len = *next;
			sol->x = x - *next + 1;
			sol->y = y - *next + 1;
		}
	}
	last_up_left = temp2;
}
