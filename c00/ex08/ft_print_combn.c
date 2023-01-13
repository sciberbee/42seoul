/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:59:56 by sebang            #+#    #+#             */
/*   Updated: 2023/01/13 10:55:02 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	process(char[]	buf, int n);
void	ft_print_combn(int n);

char	*get_max_each(void)
{
	char	max[10];

	max[0] = '0';
	max[1] = '1';
	max[2] = '2';
	max[3] = '3';
	max[4] = '4';
	max[5] = '5';
	max[6] = '6';
	max[7] = '7';
	max[8] = '8';
	max[9] = '9';
	return (max);
}

void	process(char[]	buf, int n)
{
	short	cpos;
	short	procidx;
	char	*max_each;

	cpos = n - 1;
	max_each = get_max_each();
	while (cpos >= 0)
	{
		while (buf[n - 1] <= '9')
		{
			write(1, buf, n);
			buf[n - 1] = buf[n - 1] + 1;
		}
		if (buf[cpos] == &max_each[cpos])
		{
			procidx = cpos - 1;
			buf[procidx] += 1;
			while (procidx <= (n - 1))
			{
				buf[procidx + 1] = buf[procidx] + 1;
				procidx++;
			}
			cpos--;
		}
	}
}

void	ft_print_combn(int n)
{
	char	buf[10];
	short	i;

	i = 0;
	while (i < n)
	{
		buf[i] = '0' + i++;
	}
	process(buf, n);
}

int	main(void)
{
	ft_print_combn(3);
	return (0);
}

//인트가 아니라 캐릭터로 어레이를 구성해야
//현재 예시 : n = 3일 때