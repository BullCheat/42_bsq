#ifndef READ_MAP_H
# define READ_MAP_H
# include "map.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

t_map	*read_map(int filedes);
char	transform(char c, t_map *map);

#endif
