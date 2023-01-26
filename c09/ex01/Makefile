libft.a: ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
	ar rcus libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

ft_putchar.o: ft_putchar.c
	gcc -c -o ft_putchar.o ft_putchar.c

ft_putstr.o: ft_putstr.c
	gcc -c -o ft_putstr.o ft_putstr.c

ft_strcmp.o: ft_strcmp.c
	gcc -c -o ft_strcmp.o ft_strcmp.c

ft_strlen.o: ft_strlen.c
	gcc -c -o ft_strlen.o ft_strlen.c

ft_swap.o: ft_swap.c
	gcc -c -o ft_swap.o ft_swap.c

clean :
	rm -f *.o
	rm -f $(TARGET)
