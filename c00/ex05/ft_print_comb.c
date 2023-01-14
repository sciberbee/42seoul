/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:35:54 by sebang            #+#    #+#             */
/*   Updated: 2023/01/14 16:08:02 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	w3(int digit_3);
void	ft_print_comb(void);

void	w3(int digit_3)
{
	char	char_3[5];

	char_3[0] = '0' + (digit_3 / 100);
	char_3[1] = '0' + ((digit_3 / 10) % 10);
	char_3[2] = '0' + (digit_3 % 10);
	char_3[3] = ',';
	char_3[4] = ' ';
	write(1, char_3, 5);
}

void	ft_print_comb(void)
{
	short	no;
	char	_789[3];

	_789[0] = '7';
	_789[1] = '8';
	_789[2] = '9';
	no = 012;
	while (no < 789)
	{
		if ((no / 100) < ((no / 10) % 10) && ((no / 10) % 10) < (no % 10))
		{
			w3(no);
		}
		no++;
	}
	write(1, &_789, 3);
}
