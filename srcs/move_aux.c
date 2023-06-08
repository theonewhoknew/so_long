#include "libft/libft.h"
#include "inc/so_long.h"
#include <mlx.h>
#include <stdlib.h>

void find_coin(t_game *game)
{
	if (game->map[game->row_pos][game->col_pos] == 'C')
	{
		game->coins--;
		game->map[game->row_pos][game->col_pos] = '0';
	}
}

void move_to_open_door(t_game *game, int col_pos, int row_pos)
{	
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player_at_open_door, col_pos * PIXEL, row_pos * PIXEL);
	put_tiles(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
	game->row_pos--;
	game->moves++;
	ft_printf("You won with %d total moves! Well done!\n", game->moves);
	game->victory = 1;
	ft_printf("Press R to try again or ESC to exit.\n");
	return ;

}

void move_to_door(t_game *game, int col_pos, int row_pos)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player_at_door, col_pos * PIXEL, row_pos * PIXEL);
	put_tiles(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
	ft_printf("There are %d coins remaining!\n", game->coins);
}	

void put_door(t_game *game, int col_px, int row_px)
{	
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->door, col_px, row_px);
}