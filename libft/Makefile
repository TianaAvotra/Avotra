NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c 

SRC = ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

RM = rm -f

AR = ar rcs

OBJS = $(SRCS:.c=.o)

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) -c $< -I .

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)
		
bonus: $(OBJS) $(OBJ)
		$(AR) $(NAME) $(OBJS) $(OBJ)
	
clean:
		$(RM) $(OBJS) $(OBJ)
		@echo delete with success

fclean: clean
		$(RM) $(NAME) $(OBJ) $(OBJS)
		@echo delete with success 

re: fclean all
