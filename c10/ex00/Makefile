NAME = ft_display_file
SRCS = ./ft_display_file.c
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
