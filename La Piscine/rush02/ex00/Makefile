TARGET = rush-02
SRCS = ./ft_atoi.c ./ft_chk_dict.c ./ft_chk_some.c ./ft_get_hund.c ./ft_get_thous.c ./main.c ./parse.c ./speak.c ./speak_functions.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

all: $(TARGET)

clean:

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re