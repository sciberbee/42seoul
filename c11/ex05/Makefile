NAME = do-op
SRCS = ./ft_atoi.c ./ft_do-op.c ./ft_ops.c ./ft_putnbr.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re