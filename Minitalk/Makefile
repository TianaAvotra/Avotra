SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_SRCS = server.c libft.c ft_printf.c ft_printnbr.c ft_printstr.c libft2.c
CLIENT_SRCS = client.c libft.c ft_printf.c ft_printnbr.c ft_printstr.c  libft2.c

SERVER_SRCS_BONUS = server_bonus.c libft.c ft_printf.c ft_printnbr.c ft_printstr.c  libft2.c
CLIENT_SRCS_BONUS = client_bonus.c libft.c ft_printf.c ft_printnbr.c ft_printstr.c  libft2.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

NAME = all

all: $(SERVER) $(CLIENT)

bonus:$(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(SERVER_OBJS)
	$(CC)  $(CFLAGS) -g -o $(SERVER) $(SERVER_OBJS)

$(CLIENT): $(CLIENT_OBJS)
	$(CC)  $(CFLAGS) -g -o $(CLIENT) $(CLIENT_OBJS)

$(SERVER_BONUS): $(SERVER_OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_OBJS_BONUS)

$(CLIENT_BONUS): $(CLIENT_OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_OBJS_BONUS)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus

