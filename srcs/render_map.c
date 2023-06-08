#include "libft/libft.h"
#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

void put_walls(t_game *game, int col_px, int row_px)
{	
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->wall, col_px, row_px);
}

void put_tiles(t_game *game, int col_px, int row_px)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile, col_px, row_px);
}

void put_coins(t_game *game, int col_px, int row_px)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->coin, col_px, row_px);
}

void put_player_or_exit(t_game *game, int col_px, int row_px, char c)
{	
	if (c == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player, col_px, row_px);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->door, col_px, row_px);
}

void render_map(t_game *game, int x, int y)
{	
	int col_px;
	int row_px;

	col_px = 0;
	row_px = 0;
	init_img(game);
	while (y < game->row)
	{	
		while (x < game->col)
		{	
			if(game->map[y][x] == '1')
				put_walls(game, col_px, row_px);
			else if(game->map[y][x] == '0')
				put_tiles(game, col_px, row_px);
			else if(game->map[y][x] == 'C')
				put_coins(game, col_px, row_px);
			else 
				put_player_or_exit(game, col_px, row_px, game->map[y][x]);
			col_px += 80;
			x++;
		}
		col_px = 0;
		x = 0;
		row_px += 80;
		y++;
	}
}