NAME = libftprintf.a

SRC = ft_printf.c ft_printnbr.c ft_printstr.c ft_printu.c ft_printptr.c ft_printhex.c ft_itoa.c


RM = rm -f

AR = ar rcs

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.o:.c
	$(CC) $(FLAGS) -o $@ -c $< -I

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
	
clean:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME) $(OBJ) 

re: fclean all

.PHONY:		all clean fclean re
