NAME = ft_cat
SRCS = ./ft_cat.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
