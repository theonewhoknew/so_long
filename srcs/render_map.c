#include "libft/libft.h"
#include "so_long.h"
#include <mlx.h>
/* 	

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{	
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}

	return (0);
}
	t_data	data;
	t_texture texture;
	t_img	img;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDTH, "game");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	
	img.pointer = mlx_xpm_file_to_image(data.mlx_ptr, "textures/run.xpm", &texture.width, &texture.height);

	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.pointer, 0, 0);	
 
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx_ptr);
	
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr); */

void put_walls(t_data *data, t_img *img, t_map *map)
{	
	t_texture wall;
	int y;
	int x;
	int col_pix;
	int row_pix;
	
	col_pix = 0;
	row_pix = 0;
	y = 0;
	while (y < map->row)
	{	
		while (x < map->col)
		{	
			if (map->map[y][x] == '1')
			{	
				img->img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/wall.xpm", &wall.width, &wall.height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img, col_pix, row_pix);
			}
			col_pix += 50;
			x++;
		}
		col_pix = 0;
		x = 0;
		row_pix += 50;
		y++;
	}
}

void put_tiles(t_data *data, t_img *img, t_map *map)
{
	t_texture tile;
	int y;
	int x;
	int col_pix;
	int row_pix;

	col_pix = 0;
	row_pix = 0;
	y = 0;
	while (y < map->row)
	{	
		while (x < map->col)
		{	
			if (map->map[y][x] == '0')
			{	
				img->img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/tile.xpm", &tile.width, &tile.height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img, col_pix, row_pix);
			}
			col_pix += 50;
			x++;
		}
		col_pix = 0;
		x = 0;
		row_pix += 50;
		y++;
	}
}

void put_coins(t_data *data, t_img *img, t_map *map)
{
	t_texture tile;
	int y;
	int x;
	int col_pix;
	int row_pix;

	col_pix = 0;
	row_pix = 0;
	y = 0;
	while (y < map->row)
	{	
		while (x < map->col)
		{	
			if (map->map[y][x] == 'C')
			{	
				img->img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/coin.xpm", &tile.width, &tile.height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img, col_pix, row_pix);
			}
			col_pix += 50;
			x++;
		}
		col_pix = 0;
		x = 0;
		row_pix += 50;
		y++;
	}
}

void put_exit(t_data *data, t_img *img, t_map *map)
{
	t_texture tile;
	int y;
	int x;
	int col_pix;
	int row_pix;

	col_pix = 0;
	row_pix = 0;
	y = 0;
	while (y < map->row)
	{	
		while (x < map->col)
		{	
			if (map->map[y][x] == 'E')
			{	
				img->img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/door.xpm", &tile.width, &tile.height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img, col_pix, row_pix);
			}
			col_pix += 50;
			x++;
		}
		col_pix = 0;
		x = 0;
		row_pix += 50;
		y++;
	}
}

void put_player(t_data *data, t_img *img, t_map *map)
{
	t_texture tile;
	int y;
	int x;
	int col_pix;
	int row_pix;

	col_pix = 0;
	row_pix = 0;
	y = 0;
	while (y < map->row)
	{	
		while (x < map->col)
		{	
			if (map->map[y][x] == 'P')
			{	
				img->img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/character.xpm", &tile.width, &tile.height);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img, col_pix, row_pix);
			}
			col_pix += 50;
			x++;
		}
		col_pix = 0;
		x = 0;
		row_pix += 50;
		y++;
	}
}

void render_map(t_data *data, t_img *img, t_map *map)
{
	put_walls(data, img, map);
	put_tiles(data, img, map);
	put_coins(data, img, map);
	put_exit(data, img, map);
	put_player(data, img, map);
}