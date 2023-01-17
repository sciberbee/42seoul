/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:59:56 by sebang            #+#    #+#             */
/*   Updated: 2023/01/14 16:50:40 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_combn(int n);
void	combination(int count, int start, int n, char	*buf);

void	combination(int count, int start, int n, char	*buf)
{
	int		i;

	if (count == n)
	{
		if (buf[0] == 10 - n + '0')
		{
			write(1, buf, n);
		}
		else
		{
			write(1, buf, n);
			write(1, ", ", 2);
		}
		return ;
	}
	i = start;
	while (i <= 9)
	{
		buf[count] = '0' + i;
		combination(count + 1, i + 1, n, buf);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	buf[10];

	combination(0, 0, n, buf);
}

#include <unistd.h>
int	main(void)
{
	ft_print_combn(3);
	return (0);
}
