NAME = client
NAME2 = server

all : $(NAME) $(NAME2)

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	minitalk_utils_bonus.c \
		write_func_bonus.c \
		bit_bonus.c

SRC_CLI = ft_client_bonus.c

SRC_SER = ft_server_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJ_CLI = $(SRC_CLI:%.c=%.o)
OBJ_SER = $(SRC_SER:%.c=%.o)

INCS = minitalk_bonus.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME) : $(OBJS) $(OBJ_CLI)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(OBJ_CLI)

$(NAME2) : $(OBJS) $(OBJ_SER)
	$(CC) -o $(NAME2) $(CFLAGS) $(OBJS) $(OBJ_SER)

clean :
	rm -f $(OBJS) $(OBJ_CLI) $(OBJ_SER)

fclean : clean
	rm -f $(NAME) $(NAME2)

re :
	make fclean
	make all

bonus : $(NAME) $(NAME2)

.PHONY : all clean re bonus fclean
