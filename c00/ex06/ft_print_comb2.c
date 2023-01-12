/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:36:36 by sebang            #+#    #+#             */
/*   Updated: 2023/01/12 13:57:18 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	w2_2(int no1, int no2);
void	ft_print_comb2(void);

void	w2_2(int no1, int no2)
{
	char	buf[7];

	buf[0] = '0' + (no1 / 10);
	buf[1] = '0' + (no1 % 10);
	buf[2] = ' ';
	buf[3] = '0' + (no2 / 10);
	buf[4] = '0' + (no2 % 10);
	buf[5] = ',';
	buf[6] = ' ';
	write(1, buf, 7);
}

void	ft_print_comb2(void)
{
	int	no1;
	int	no2;

	no1 = 00;
	no2 = 01;
	while (no1 < no2)
	{
		w2_2(no1, no2);
		no2++;
		if (no2 == 99)
		{
			no1++;
			no2 = no1 + 1;
		}
		if (no1 == 98)
		{
			break ;
		}
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
