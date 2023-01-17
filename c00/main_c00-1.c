#include <stdio.h>
#include <limits.h>

#include "ex00/ft_putchar.c"
#include "ex01/ft_print_alphabet.c"
#include "ex02/ft_print_reverse_alphabet.c"
#include "ex03/ft_print_numbers.c"
#include "ex04/ft_is_negative.c"
#include "ex05/ft_print_comb.c"
#include "ex06/ft_print_comb2.c"
#include "ex07/ft_putnbr.c"
#include "ex08/ft_print_combn.c"

int	main(void)
{
	printf("\n----ex00----\n");
	ft_putchar('a');
	printf("\na : 같으면 답\n");

	printf("\n----ex01----\n");
	ft_print_alphabet();
	printf("\nabcdefghijklmnopqrstuvwxyz : 같으면 답\n");

	printf("\n----ex02----\n");
	ft_print_reverse_alphabet();
	printf("\nzyxwvutsrqponmlkjihgfedcba : 같으면 답\n");

	printf("\n----ex03----\n");
	ft_print_numbers();
	printf("\n0123456789 : 같으면 답\n");

	printf("\n----ex04----\n");
	ft_is_negative(INT_MIN);
	printf("\n음수 일 때 : N\n");
	ft_is_negative(0);
	printf("\n 0   일 때 : P\n");
	ft_is_negative(INT_MAX);
	printf("\n양수 일 때 : P\n");

	printf("\n----ex05----\n");
	ft_print_comb();
	printf("\n");

	printf("\n----ex06----\n");
	ft_print_comb2();
	printf("\n");

	printf("\n----ex07----\n");
	write(1, " ", 1);
	ft_putnbr(INT_MAX);
	printf("\n 2147483647 : 정수형최댓값\n");
	ft_putnbr(INT_MIN);
	printf("\n-2147483648 : 정수형최솟값\n");
	ft_putnbr(0);
	printf("\n0 : 알고리즘에 따라 예외 일 수도?\n");
	ft_putnbr(7);
	printf("\n7 : 한 자리 정수\n");
	ft_putnbr(1457);
	printf("\n1457 : 네 자리 양수\n");
	ft_putnbr(-4242);
	printf("\n-4242 : 네 자리 음수\n");

	printf("\n----ex08----\n");
	for (int i= 1; i <= 9; i++)
	{
		ft_print_combn(i);
		printf("\nn = %d 일 때\n\n", i);
	}
	printf("\n고생하셨습니다.\n\n");
	return(0);
}
