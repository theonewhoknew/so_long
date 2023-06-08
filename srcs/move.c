#include "libft/libft.h"
#include "inc/so_long.h"
#include <mlx.h>
#include <stdlib.h>

void move_player(t_game *game, int col_px, int row_px)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player, col_px, row_px);
}

void move_up(t_game *game)
{	
	if (game->map[game->row_pos - 1][game->col_pos] == '1')
		return ;
	else
	{	
		if (game->map[game->row_pos - 1][game->col_pos] == 'E' && game->coins == 0)
		{
			move_to_open_door(game, game->col_pos, game->row_pos - 1);
			return ;
		}
		else if (game->map[game->row_pos - 1][game->col_pos] == 'E')
			move_to_door(game, game->col_pos, game->row_pos - 1);
		else if (game->map[game->row_pos][game->col_pos] == 'E')
		{
			move_player(game, (game->col_pos) * PIXEL, (game->row_pos - 1) * PIXEL);
			put_door(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
		}
		else
		{
			move_player(game, (game->col_pos) * PIXEL, (game->row_pos - 1) * PIXEL);
			put_tiles(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
		}
		game->row_pos--;
		game->moves++;
		find_coin(game);
		ft_printf("Total moves: %d\n", game->moves);
	}
}

void move_down(t_game *game)
{	
	if (game->map[game->row_pos + 1][game->col_pos] == '1')
		return ;
	else
	{	
		if (game->map[game->row_pos + 1][game->col_pos] == 'E' && game->coins == 0)
			move_to_open_door(game, game->col_pos, game->row_pos + 1);
		else if (game->map[game->row_pos + 1][game->col_pos] == 'E')
			move_to_door(game, game->col_pos, game->row_pos + 1);
		else if (game->map[game->row_pos][game->col_pos] == 'E')
		{
			move_player(game, (game->col_pos) * PIXEL, (game->row_pos + 1) * PIXEL);
			put_door(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
		}
		else
		{
			move_player(game, (game->col_pos) * PIXEL, (game->row_pos + 1) * PIXEL);
			put_tiles(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
		}
		game->row_pos++;
		game->moves++;
		find_coin(game);
		ft_printf("Total moves: %d\n", game->moves);
	}
}

void move_left(t_game *game)
{	
	if (game->map[game->row_pos][game->col_pos - 1] == '1')
		return ;
	else
	{	
		if (game->map[game->row_pos][game->col_pos - 1] == 'E' && game->coins == 0)
			move_to_open_door(game, game->col_pos - 1, game->row_pos);
		else if (game->map[game->row_pos][game->col_pos - 1] == 'E')
			move_to_door(game, game->col_pos - 1, game->row_pos);
		else if (game->map[game->row_pos][game->col_pos] == 'E')
		{
			move_player(game, (game->col_pos - 1) * PIXEL, (game->row_pos) * PIXEL);
			put_door(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
		}
		else
		{
			move_player(game, (game->col_pos - 1) * PIXEL, (game->row_pos) * PIXEL);
			put_tiles(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
		}
		game->col_pos--;
		game->moves++;
		find_coin(game);
		ft_printf("Total moves: %d\n", game->moves);
	}
}

void move_right(t_game *game)
{	
	if (game->map[game->row_pos][game->col_pos + 1] == '1')
		return ;
	else
	{	
		if (game->map[game->row_pos][game->col_pos + 1] == 'E' && game->coins == 0)
			move_to_open_door(game, game->col_pos + 1, game->row_pos);
		else if (game->map[game->row_pos][game->col_pos + 1] == 'E')
			move_to_door(game, game->col_pos + 1, game->row_pos);
		else if (game->map[game->row_pos][game->col_pos] == 'E')
		{
			move_player(game, (game->col_pos + 1) * PIXEL, (game->row_pos) * PIXEL);
			put_door(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
		}
		else
		{
			move_player(game, (game->col_pos + 1) * PIXEL, (game->row_pos) * PIXEL);
			put_tiles(game, (game->col_pos) * PIXEL, (game->row_pos) * PIXEL);
		}
		game->col_pos++;
		game->moves++;
		find_coin(game);
		ft_printf("Total moves: %d\n", game->moves);
	}
}
