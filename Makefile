NAME = so_long

LIBFT_DIR = libft

LIBFT =  $(LIBFT_DIR)/libft.a
	
SRCS = $(addprefix srcs/, main.c bounce_map.c struct_init.c get_things.c check_map.c check_walls.c check_path.c)

OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))

OBJECTS_DIR = objs

CFLAGS = -Wall -Werror -Wextra -I . 

all: make_libft $(NAME) 

$(NAME) : $(OBJS) so_long.h 
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

objs/%.o : srcs/%.c so_long.h libft/libft.h | $(OBJECTS_DIR)
	gcc -c  $(CFLAGS) $< -o $@

$(OBJECTS_DIR) :
	mkdir -p objs

make_libft:
	@make -C $(LIBFT_DIR)

clean:
	@rm -f *.o
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean all bonus clean fclean re