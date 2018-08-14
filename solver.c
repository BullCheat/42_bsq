// FIXME header

#include <stdbool.h>
#include "solver.h"
#define IGNORE 2

int min(int a, int b) {
	return a < b ? a : b;
}

char getCell(int x, int y, map *map) {
	// printf("Access %d\n", x + y * map->width);
	return map->tab[x + y * map->width];
}

char ignore(int x, int y, map *map) {
	map->tab[x + y * map->width] |= IGNORE;
	return getCell(x, y, map);
}

solution *solve(map *map)
{
	solution *sol = malloc(sizeof(struct solution));
	for (int x = 0; x < map->width; x++) {
		// TODO optimize do not browse useless indexes
		for (int y = 0; y < map->width; y++) {
			// TODO optimize do not browse useless indexes
			// For each cell
			char c = getCell(x, y, map);
			if (c & IGNORE) continue; // TODO optimize
			if (c & 1) continue; // if there's an obstacle
			int end = min(map->width - x, map->height - x); // Max diagonal distance we can go to
			if (end < sol->len) continue; // TODO optimize
			for (int i = 1; i < end; i++) {
				bool br = 0;
				for (int x1 = 0; x1 < i; x1++) {
					char c = ignore(x1 + x, y + i, map);
					if (br = c & 1)
						break ;
				}
				if (!br)
					for (int y1 = 0; y1 < i; y1++) {
						char c = ignore(x + i, y1 + y, map);
						if (br = c & 1)
							break ;
					}
				if (br)
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