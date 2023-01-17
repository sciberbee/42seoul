/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:54:10 by sebang            #+#    #+#             */
/*   Updated: 2023/01/17 13:08:25 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	process_negative(void);
void	process_int_min(void);
void	print_nb(int nb);

void	process_negative(void)
{
	write(1, "-", 1);
}

void	process_int_min(void)
{
	int		int_max;
	int		i;
	char	string_int_min[10];

	int_max = 2147483647;
	i = 9;
	while (i >= 0)
	{
		string_int_min[i] = (int_max % 10) + '0';
		int_max = int_max / 10;
		i--;
	}
	string_int_min[9] = '8';
	process_negative();
	write(1, string_int_min, 10);
}

void	print_nb(int nb)
{
	char	stack[10];
	int		i;

	if (nb == -2147483648)
	{
		process_int_min();
		return ;
	}
	if (nb < 0)
	{
		process_negative();
		nb = -nb;
	}
	i = 0;
	while (nb)
	{
		stack[i++] = '0' + (nb % 10);
		nb = nb / 10;
	}
	i--;
	while (i >= 0)
	{
		write(1, stack + (i--), 1);
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
