// FIXME header

#include <stdio.h>
#include "map.h"
#define IGNORE 2

int min(int a, int b) {
	return a < b ? a : b;
}

char getCell(int x, int y, map map) {
	return map.tab[x + y * map.width];
}

solution solve(map map)
{
	solution sol;
	for (int x = 0; x < map.width; x++) {
		// TODO optimize do not browse useless indexes
		for (int y = 0; y < map.width; y++) {
			// TODO optimize do not browse useless indexes
			// For each cell
			char c = getCell(x, y, map);
			if (c & IGNORE) continue; // TODO optimize
			if (c & 1) continue; // if there's an obstacle
			int end = min(map.width - x, map.height - x); // Max diagonal distance we can go to
			if (end < sol.len) continue; // TODO optimize
			for (int i = 1; i < end; i++) {
				if (getCell(x + i, y + i, map) & 1) // if there's an obstacle
				{
					if (i > sol.len)
					{
						sol.len = i;
						sol.x = x;
						sol.y = y;
					}
					break;
				}
			}
		}
	}
	return sol;
}