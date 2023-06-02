#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void fill_struct(t_map *map, char *path)
{
	bounce_map(map, path);
	get_row_col(map);
	get_coins(map);
	get_exit(map);
	get_position(map);
}

void initialize_struct(t_map *map)
{	
	map->col = 0;
	map->row = 0;
	map->exit = 0;
	map->coins = 0;
	map->position = 0;
	map->row_pos = 0;
	map->col_pos = 0;
	map->map = NULL;
}