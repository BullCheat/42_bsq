#ifndef READ_MAP_H
# define READ_MAP_H
# include "map.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

map	*read_map(int filedes);

#endif