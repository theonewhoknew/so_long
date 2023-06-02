#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 400
# define MLX_ERROR 1

typedef struct s_texture
{
	char	*relative_path;
	int		width;
	int		height;
}					t_texture;

typedef struct	s_img
{
	void		*pointer;
	size_t		size;
	char      	*pixels;
	int       	bits_per_pixel;
	int       	line_size;
	int       	endian;
}  					 t_img;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img *img;
}				t_data;

typedef struct s_map
{
	int col;
	int row;
	int	exit;
	int coins;
	int initial;
}				t_map;

#endif