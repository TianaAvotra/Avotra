NAME_ARCH = push_swap.ar
NAME = push_swap

SRC =  ft_error.c ft_libft.c instruction.c list.c push_swap.c push.c reverse_rotate.c rotate.c sort.c swap.c \
target.c ft_libft2.c instruction2.c	target2.c main.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(NAME_ARCH)
	${CC} $(NAME_ARCH) -o $(NAME)

$(NAME_ARCH): $(OBJ)
	@ar rcs $(NAME_ARCH) $(OBJ)

.c.o:
	${CC} ${FLAGS} -o ${<:.c=.o} -c $<

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f ${NAME} ${NAME_ARCH}

re: fclean all

.PHONY: all, clean, fclean, re
