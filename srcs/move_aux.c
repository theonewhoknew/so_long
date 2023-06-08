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
	game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/character_in_open_door.xpm", &(game->width), &(game->height));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_pos * PIXEL, row_pos * PIXEL);
	put_tiles(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
	game->row_pos--;
	game->moves++;
	ft_printf("You won with %d total moves! Well done!\n", game->moves);
	return ;

}

void move_to_door(t_game *game, int col_pos, int row_pos)
{
	game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/character_in_door.xpm", &(game->width), &(game->height));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_pos * PIXEL, row_pos * PIXEL);
	put_tiles(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
	ft_printf("There are %d coins remaining!\n", game->coins);
}	

void put_door(t_game *game, int col_px, int row_px)
{	
	ft_printf("entra aqui\n");
	game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/door.xpm", &(game->width), &(game->height));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_px, row_px);
}
