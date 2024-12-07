NAME = philo

SRC = main.c ft_utils.c ft_check.c ft_routine.c ft_fork.c utils.c  ft_time.c ft_init.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror 

RM = rm -f

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) -g -o $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(FLAGS) -c $< -g -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
