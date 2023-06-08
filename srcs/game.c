#include "libft/libft.h"
#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

int	handle_no_event()
{
	
	return (0);
}

int	key_press(int keycode, t_game *game)
{	
	if (keycode == W)
		move_up(game);
	else if (keycode == S)
		move_down(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == D)
		move_right(game);
	else if (keycode == ESC)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	return (1);
}

void run_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 80 * game->col, 80 * game->row, "game");
	render_map(game, 0, 0);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_hook(game->win_ptr, 2, 1L<<0, &key_press, game);
	mlx_loop(game->mlx_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	return ;
}