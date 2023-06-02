NAME = so_long

LIBFT_DIR = libft

LIBFT =  $(LIBFT_DIR)/libft.a
	
SRCS = main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I . 

all: make_libft $(NAME) 

$(NAME) : $(OBJS) so_long.h 
	gcc $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS)

%.o : %.c so_long.h libft/libft.h
	gcc -c  $(CFLAGS) $< -o $@

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