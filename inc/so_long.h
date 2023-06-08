#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 400
# define MLX_ERROR 1
# define ERROR -1
# define SUCCESS 0
# define W 119
# define A 97
# define S 115
# define D 100
# define R 114
# define ESC 65307
# define PIXEL 80
# define UP	1
# define RIGHT	2
# define DOWN	3
# define LEFT	4

typedef struct s_img
{
	void *wall;
	void *tile;
	void *coin;
	void *door;
	void *player;
	void *player_at_door;
	void *player_at_open_door;
}				t_img;

typedef struct s_game
{	
	void 	*mlx_ptr;
	void 	*win_ptr;
	t_img	*img;
	char     *addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char **map;
	char **visited;
	char *path;
	char	*relative_path;
	int		width;
	int		height;
	int 	col;
	int 	row;
	int		exit;
	int 	path_exit;
	int 	coins;
	int 	path_coins;
	int 	position;
	int 	row_pos;
	int 	col_pos;
	int 	moves;
	int		victory;
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
void put_tiles(t_game *game, int col_px, int row_px);
void move_up(t_game *game);
void move_down(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);
void move_to_door(t_game *game, int col_pos, int row_pos);
void move_to_open_door(t_game *game, int col_pos, int row_pos);
void put_door(t_game *game, int col_pos, int row_pos);
void find_coin(t_game *game);
void reset(t_game *game);
void free_struct(t_game *game);
void init_img(t_game *game);

#endif