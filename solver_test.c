// FIXME HEADER

#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "solver.h"

#define LEN 20
// Every 20 cells one obstacle
#define DENSITY 25

int main() {
	map *m = malloc(sizeof(struct map));
	char *mem = malloc(LEN * LEN);
	m->tab = mem;
	m->width = m->height = LEN;
	m->empty = ' ';
	m->full = 'X';
	m->obstacle = 'o';
	solution *sol = solve(m);
	for (int x = 0; x < LEN; x++) {
		for (int y = 0; y < LEN; y++) {
			char v = (rand() % DENSITY) == 0;
			m->tab[x + LEN * y] = v;
			if (x >= sol->x && x <= sol->x + sol->len && y >= sol->y && y <= sol->y + sol->len)
				printf("%c", m->full);
			else
				printf("%c", v ? m->obstacle : m->empty);
		}
		printf("\n");
	}
	printf("Solution: len = %d, x = %d, y = %d\n", sol->len, sol->x, sol->y);
}