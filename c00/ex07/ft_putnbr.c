/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:54:10 by sebang            #+#    #+#             */
/*   Updated: 2023/01/12 12:10:52 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb);
char	itoc(int no);
void	process_negative(int is_negative);
void	print_nb(int nb);

int	main(void)
{
	ft_putnbr(2147483647);
	return (0);
}

char	itoc(int no)
{
	char	numbers[10];

	numbers[0] = '0';
	numbers[1] = '1';
	numbers[2] = '2';
	numbers[3] = '3';
	numbers[4] = '4';
	numbers[5] = '5';
	numbers[6] = '6';
	numbers[7] = '7';
	numbers[8] = '8';
	numbers[9] = '9';
	return (numbers[no]);
}

void	process_negative(int is_negative)
{
	char	minus;

	if (is_negative)
	{
		minus = '-';
		write(1, &minus, 1);
	}
}

void	print_nb(int nb)
{
	char	stack[10];
	long	i;
	long	is_negative;

	is_negative = 0;
	i = 0;
	if (nb < 0)
	{
		is_negative = 1;
		nb = -nb;
	}
	while (nb)
	{
		stack[i++] = itoc(nb % 10);
		nb = nb / 10;
	}
	process_negative(is_negative);
	while (i - 1 >= 0)
	{
		write(1, stack + (i - 1), 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char	char_zero;

	char_zero = '0';
	if (nb == 0)
	{
		write(1, &char_zero, 1);
	}
	else
	{
		print_nb(nb);
	}
}
