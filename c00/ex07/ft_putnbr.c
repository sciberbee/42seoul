/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:54:10 by sebang            #+#    #+#             */
/*   Updated: 2023/01/11 20:55:25 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb);

int	main(void)
{
	ft_putnbr(-2051);
	return (0);
}

void	ft_putnbr(int nb)
{
	int	idx;
	int	current;
	int	i;
	char	little_str[10];
	char	big_str[10];

	i = 0;
	for (i = 0; i < 10; i++)
	{
		little_str[i] = 0;
	}
	idx = 0;
	if (nb < 0)
	{
		little_str[idx++] = '-';
		nb = -nb;
	}
	while (nb > 10)
	{
		current = nb / 10;
		nb = nb % 10;
		little_str[idx++] = 48 + current;
	}
	little_str[idx++] = 48 + nb;
	little_str[idx++] = '\0';
	for (i = 0; i <= idx; i++)
	{
		big_str[i] = little_str[9-i];
	}
	printf(little_str);
	printf(big_str);
}
