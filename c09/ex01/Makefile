.SUFFIXES : .c .o

TARGET = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJECTS = ./srcs/ft_putchar.o ./srcs/ft_putstr.o ./srcs/ft_strcmp.o ./srcs/ft_strlen.o ./srcs/ft_swap.o
INCLUDE_PATH = ./includes/
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
AFLAGS = rcus

$(TARGET): $(OBJECTS)
	$(AR) $(AFLAGS) $(TARGET) $(OBJECTS)

all: $(TARGET)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re