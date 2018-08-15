// FIXME HEADER

#ifndef BSQ_SOLVE_H
#define BSQ_SOLVE_H

#include "map.h"
#include <stdlib.h>

void initialize(int width);
void parse(char c, int x, int y);
t_solution *get_solution();
t_solution *solve(t_map *map);
t_solution *solve_1(t_map *map);

#endif //BSQ_SOLVE_H
