#include "inc/so_long.h"

void reset(t_game *map)
{   
    bounce_map(map, map->path);
    get_coins(map);
	get_exit(map);
	get_position(map);
    get_pos_coord(map);
    render_map(map, 0, 0);
}