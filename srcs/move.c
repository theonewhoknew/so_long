#include "libft/libft.h"
#include "so_long.h"
#include <mlx.h>

void move_player(t_game *game, int col_px, int row_px)
{
	game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/character.xpm", &(game->width), &(game->height));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_px, row_px);
}

void move_up(t_game *game)
{	
	if (game->map[game->row_pos - 1][game->col_pos] == '1')
	{	
		ft_printf("Blocked.\n");
		return ;
	}
	else
	{	
		ft_printf("moved\n");
		move_player(game, (game->col_pos) * 50, (game->row_pos - 1) * 50);
		put_tiles(game, (game->col_pos) * 50, (game->row_pos) * 50);
		game->row_pos--;
		game->moves++;
		if (game->map[game->row_pos][game->col_pos] == 'C')
		{
			game->coins--;
			game->map[game->row_pos][game->col_pos] = '0';
		}
		ft_printf("Total moves: %d\n", game->moves);
	}
}

void move_down(t_game *game)
{	
	if (game->map[game->row_pos + 1][game->col_pos] == '1')
	{	
		ft_printf("Blocked.\n");
		return ;
	}
	else
	{	
		ft_printf("moved\n");
		move_player(game, (game->col_pos) * 50, (game->row_pos + 1) * 50);
		put_tiles(game, (game->col_pos) * 50, (game->row_pos) * 50);
		game->row_pos++;
		game->moves++;
		if (game->map[game->row_pos][game->col_pos] == 'C')
		{
			game->coins--;
			game->map[game->row_pos][game->col_pos] = '0';
		}
		ft_printf("Total moves: %d\n", game->moves);
	}
}

void move_left(t_game *game)
{	
	if (game->map[game->row_pos][game->col_pos - 1] == '1')
	{	
		ft_printf("Blocked.\n");
		return ;
	}
	else
	{	
		ft_printf("moved\n");
		move_player(game, (game->col_pos - 1) * 50, (game->row_pos) * 50);
		put_tiles(game, (game->col_pos) * 50, (game->row_pos) * 50);
		game->col_pos--;
		game->moves++;
		if (game->map[game->row_pos][game->col_pos] == 'C')
		{
			game->coins--;
			game->map[game->row_pos][game->col_pos] = '0';
		}
		ft_printf("Total moves: %d\n", game->moves);
	}
}

void move_right(t_game *game)
{	
	ft_printf("%d %d", game->col_pos, game->row_pos);
	if (game->map[game->row_pos][game->col_pos + 1] == '1')
	{	
		ft_printf("Blocked.\n");
		return ;
	}
	else
	{	
		ft_printf("moved\n");
		move_player(game, (game->col_pos + 1) * 50, (game->row_pos) * 50);
		put_tiles(game, (game->col_pos) * 50, (game->row_pos) * 50);
		game->col_pos++;
		game->moves++;
		ft_printf("crash\n");
		if (game->map[game->row_pos][game->col_pos] == 'C')
		{
			game->coins--;
			game->map[game->row_pos][game->col_pos] = '0';
		}
		ft_printf("Total moves: %d\n", game->moves);
	}
}
