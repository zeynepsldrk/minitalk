CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MAND = mandatory
BON = bonus

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRCS_SERVER        = $(MAND)/server.c $(MAND)/minitalk_utils.c
SRCS_CLIENT        = $(MAND)/client.c $(MAND)/minitalk_utils.c
SRCS_SERVER_BONUS  = $(BON)/server_bonus.c $(BON)/minitalk_utils_bonus.c
SRCS_CLIENT_BONUS  = $(BON)/client_bonus.c $(BON)/minitalk_utils_bonus.c

OBJS_SERVER        = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT        = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS  = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS  = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $^ -o $@
$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) $^ -o $@
$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
re: fclean all

.PHONY: all bonus clean fclean re
