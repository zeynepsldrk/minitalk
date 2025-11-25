SERVER_SRCS	= server.c minitalk_utils.c
CLIENT_SRCS	= client.c minitalk_utils.c
SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS	= $(CLIENT_SRCS:.c=.o)
SERVER		= server
CLIENT		= client
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
HEADER		= minitalk.h

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(SERVER_OBJS)
			$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT):	$(CLIENT_OBJS)
			$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

server.o:	server.c $(HEADER)
			$(CC) $(CFLAGS) -c server.c -o server.o

client.o:	client.c $(HEADER)
			$(CC) $(CFLAGS) -c client.c -o client.o

minitalk_utils.o:	minitalk_utils.c $(HEADER)
					$(CC) $(CFLAGS) -c minitalk_utils.c -o minitalk_utils.o

clean:
			$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:		clean
			$(RM) $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re