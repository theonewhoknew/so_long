#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 400
# define MLX_ERROR 1
# define ERROR -1
# define SUCCESS 0

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
	char **map;
	int col;
	int row;
	int	exit;
	int coins;
	int position;
	int row_pos;
	int col_pos;
}				t_map;

void bounce_map(t_map *map, char *path);
void fill_struct(t_map *map, char *path);
void initialize_struct(t_map *map);
void get_row_col(t_map *map);
void get_coins(t_map *map);
void get_exit(t_map *map);
void get_position(t_map *map);
int check_extension(char *path);
int check_map(int argc, char *path,  t_map *map);
int check_walls(t_map *map);
void get_pos_coord(t_map *map);
int check_path(t_map *map);

#endif