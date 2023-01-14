/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:09:27 by taehkim2          #+#    #+#             */
/*   Updated: 2023/01/14 17:01:52 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int		atoi(const char *str);

int	main(int ac, char **av)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (ac == 3 && x >= 0 && y >= 0)
	{
		x = atoi(av[1]);
		y = atoi(av[2]);
		rush(x, y);
	}
	write(1, "\n", 1);
	rush(5, 3);
	write(1, "\n", 1);
	rush(5, 1);
	write(1, "\n", 1);
	rush(1, 1);
	write(1, "\n", 1);
	rush(1, 5);
	write(1, "\n", 1);
	rush(4, 4);
	return (0);
}

int	atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
