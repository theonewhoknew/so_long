#include "libft/libft.h"
#include "so_long.h"
#include <mlx.h>

void game(t_map *map)
{
	t_data	data;
	t_img img;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 50 * map->col, 50 * map->row, "game");
	render_map(&data, &img, map);
	mlx_loop(data.mlx_ptr);
}