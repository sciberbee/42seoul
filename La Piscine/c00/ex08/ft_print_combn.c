/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:59:56 by sebang            #+#    #+#             */
/*   Updated: 2023/01/17 13:02:42 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	ft_put_comb(int idx, int start, int n, char	*buf);

void	ft_put_comb(int idx, int start, int n, char	*buf)
{
	int		i;

	if (idx == n)
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
		buf[idx] = '0' + i;
		ft_put_comb(idx + 1, i + 1, n, buf);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	buf[10];

	ft_put_comb(0, 0, n, buf);
}
