

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