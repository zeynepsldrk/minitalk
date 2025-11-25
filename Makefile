CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SERVER_SRC = server.c minitalk_utils.c
CLIENT_SRC = client.c minitalk_utils.c

BONUS_SERVER_SRC = server_bonus.c minitalk_utils_bonus.c
BONUS_CLIENT_SRC = client_bonus.c minitalk_utils_bonus.c

SERVER_OBJS = server.o minitalk_utils.o
CLIENT_OBJS = client.o minitalk_utils.o
BONUS_SERVER_OBJS = server_bonus.o minitalk_utils_bonus.o
BONUS_CLIENT_OBJS = client_bonus.o minitalk_utils_bonus.o

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS)

bonus: $(BONUS_SERVER_OBJS) $(BONUS_CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(BONUS_SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(BONUS_CLIENT_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re
