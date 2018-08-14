// FIXME header

#include "solver.h"
#define IGNORE 2

int min(int a, int b) {
	return a < b ? a : b;
}

char getCell(int x, int y, t_map *map) {
	// printf("Access %d\n", x + y * map->width);
	return map->tab[x + y * map->width];
}

char ignore(int x, int y, t_map *map) {
	char c = getCell(x, y, map);
	map->tab[x + y * map->width] |= IGNORE;
	return c;
}

t_solution *allocate_solution() {
	t_solution *s = malloc(sizeof(t_solution));
	s->len = 0;
	s->x = 0;
	s->y = 0;
	return s;
}

char check_vertical(int x, int y, int len, t_map *map) {
	for (int i = 0; i <= len; i++) {
		if (map->tab[(x + len) + (y + i) * map->width] & 1)
			return 0;
	}
	return 1;
}
char check_horizontal(int x, int y, int len, t_map *map) {
	for (int i = 0; i <= len; i++) {
		if (map->tab[(x + i) + (y + len) * map->width] & 1)
			return 0;
	}
	return 1;
}

t_solution *solve(t_map *map)
{
	t_solution *sol = allocate_solution();
	for (int y = 0; y < map->width; y++) {
		// TODO optimize do not browse useless indexes
		for (int x = 0; x < map->width; x++) {
			// TODO optimize do not browse useless indexes
			// For each cell
			char c = ignore(x, y, map);
			// if (c & IGNORE) continue; // TODO optimize
			if (c & 1) continue; // if there's an obstacle
			int end = min(map->width - x, map->height - y); // Max diagonal distance we can go to
			if (end < sol->len) continue; // TODO optimize
			for (int i = 1; i <= end; i++) {
				char a = check_vertical(x, y, i, map);
				char b = check_horizontal(x, y, i, map);
				if (x== 0 && y == 2)
					printf("");
				if (!a || !b || i == end)
				{
					if (i > sol->len)
					{
						sol->len = i;
						sol->x = x;
						sol->y = y;
					}
					break;
				}
			}
		}
	}
	return sol;
}