#include "libft/libft.h"
#include "so_long.h"
#include <mlx.h>

void run_game(t_game *game)
{

	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 50 * game->col, 50 * game->row, "game");
	render_map(game, 0, 0);
	mlx_loop(game->mlx_ptr);
}