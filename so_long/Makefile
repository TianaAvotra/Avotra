NAME = so_long

SRC = so_long.c close_window.c get_next_line.c get_next_line_utils.c read_map.c ft_count.c ft_check.c ft_free.c libft.c ft_init_image.c move_player.c position.c
FLAGS = -Wall -Wextra -Werror

FLAGS_MINI = -L./minilibx-linux -lmlx -lXext -lX11 -lm

LIB_MLX = ./minilibx-linux/libmlx.a

FT_PRINTF = ./printf/libftprintf.a

RM = rm -f

CC = cc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB_MLX) $(FT_PRINTF)
	$(CC) $(FLAGS) -g -o $(NAME) $(OBJ) $(LIB_MLX) $(FT_PRINTF) $(FLAGS_MINI)

$(LIB_MLX):
	@make -C ./minilibx-linux

$(FT_PRINTF):
	@make -C ./printf

%.o: %.c
	$(CC) $(FLAGS) -c $< -g -o $@

clean:
	$(RM) $(OBJ)
	make -C ./minilibx-linux clean
	@make clean -C ./printf

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
