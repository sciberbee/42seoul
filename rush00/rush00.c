/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:09:00 by taehkim2          #+#    #+#             */
/*   Updated: 2023/01/14 14:01:39 by taehkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	a;
	int	b;

	a = x;
	b = y;
	if (x < 0 || y < 0)
		return ;
	while (y > 0)
	{
		x = a;
		while (x > 0)
		{
			if ((x == a || x == 1) && (y == b || y == 1))
				ft_putchar('o');
			else if ((y < b && y > 1) && (x < a && x > 1))
				ft_putchar(' ');
			else if ((y < b && y > 1) && (x == a || x == 1))
				ft_putchar('|');
			else if ((x < a || x > 1) && (y == b || y == 1))
				ft_putchar('-');
			x--;
		}
		ft_putchar('\n');
		y--;
	}
}
