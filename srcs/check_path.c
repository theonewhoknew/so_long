#include "so_long.h"
#include <stdlib.h>

int is_valid_move(t_map *map, int row, int col) {
    if (row < 0 || row >= map->row || col < 0 || col >= map->col)
	{	
		ft_printf("imprime esto\n");
		return (ERROR);
	}
    if (map->map[row][col] == '1')
        return (ERROR);
	else
   		return (SUCCESS);
}

int dfs(t_map *map, int row, int col)
{	
	if (is_valid_move(map, row, col) == ERROR)
		return (ERROR);
	if (map->map[row][col] == 'E' && map->coins == 0)
        return (SUCCESS);
	if (map->map[row][col] == 'C')
	{
		map->coins--;
		map->map[row][col] = 'V';
	}
	dfs(map, row - 1, col); // Up
    dfs(map, row, col + 1); // Right
	dfs(map, row + 1, col); // Down
	dfs(map, row, col - 1); // Left 
	return (ERROR);
}

int check_path(t_map *map)
{
	t_map path;

	get_pos_coord(map);
	path = *map;
	if (dfs(&path, path.row_pos, path.col_pos) == ERROR)
		return (ERROR);
	else
		return (SUCCESS); 

}