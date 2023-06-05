#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 400
# define MLX_ERROR 1
# define ERROR -1
# define SUCCESS 0

typedef struct s_game
{	
	void 	*mlx_ptr;
	void 	*win_ptr;
	void	*img;
	char     *addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char **map;
	char **visited;
	char	*relative_path;
	int		width;
	int		height;
	int col;
	int row;
	int	exit;
	int path_exit;
	int coins;
	int path_coins;
	int position;
	int row_pos;
	int col_pos;
}				t_game;


void bounce_map(t_game *map, char *path);
void fill_struct(t_game *map, char *path);
void initialize_struct(t_game *map);
void get_row_col(t_game *map);
void get_coins(t_game *map);
void get_exit(t_game *map);
void get_position(t_game *map);
int check_extension(char *path);
int check_map(int argc, char *path,  t_game *map);
int check_walls(t_game *map);
void get_pos_coord(t_game *map);
int check_path(t_game *map);
void run_game(t_game *map);
void render_map(t_game *game, int x, int y);

#endif