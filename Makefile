NAME = so_long

LIBFT_DIR = libft

LIBFT =  $(LIBFT_DIR)/libft.a
	
SRCS = $(addprefix srcs/, main.c bounce_map.c struct_init.c get_things.c check_map.c check_walls.c check_path.c render_map.c \
		game.c move.c move_aux.c)

OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))

OBJECTS_DIR = objs

INC_DIR = inc

CFLAGS =  -Wall -Werror -Wextra -I $(INC_DIR) 

all: make_libft $(NAME) 

$(NAME) : $(OBJS) $(INC_DIR)/so_long.h 
	cc $(CFLAGS)  -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

objs/%.o : srcs/%.c $(INC_DIR)/so_long.h libft/libft.h | $(OBJECTS_DIR)
	cc -c  $(CFLAGS) -I . -Imlx_linux -O3 $< -o $@

$(OBJECTS_DIR) :
	mkdir -p objs

make_libft:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf objs
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean all bonus clean fclean re