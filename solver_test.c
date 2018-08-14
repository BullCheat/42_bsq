// FIXME HEADER

#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "solver.h"

#define LEN 20
// Every 20 cells one obstacle
#define DENSITY 50

int main() {
	t_map *m = malloc(sizeof(t_map));
	m->tab = malloc(LEN * LEN);
	m->width = m->height = LEN;
	m->empty = ' ';
	m->full = 'X';
	m->obstacle = 'o';
	srand(0);
	for (int y = 0; y < LEN; y++) {
		for (int x = 0; x < LEN; x++) {
			char v = (rand() % DENSITY) == 0;
			m->tab[x + LEN * y] = v;
			printf("%c", m->tab[x + LEN * y] ? m->obstacle : m->empty);
		}
		printf("\n");
	}
	printf("\n--------------------\n\n");
	t_solution *sol = solve(m);
	for (int y = 0; y < LEN; y++) {
		for (int x = 0; x < LEN; x++) {
			if (x >= sol->x && x < sol->x + sol->len && y >= sol->y && y < sol->y + sol->len)
				printf("%c", m->tab[x + LEN * y] & 1 ? '.' : m->full);
			else
				printf("%c", m->tab[x + LEN * y] & 1 ? m->obstacle : m->empty);
		}
		printf("\n");
	}
	printf("Solution: len = %d, x = %d, y = %d\n", sol->len, sol->x, sol->y);
}