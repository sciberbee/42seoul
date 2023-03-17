/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:01:24 by sebang            #+#    #+#             */
/*   Updated: 2023/01/20 22:09:33 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_ten_queens_puzzle(void);

void	print_board(int	*board)
{
	int		i;
	char	ch;

	i = 0;
	while (i < 10)
	{
		ch = '0' + board[i];
		write(1, &ch, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	good(int i, int *board)
{
	int	k;

	k = i - 1;
	while (k >= 0)
	{
		if ((board[i] == board[k])
			|| abs(board[i] - board[k]) == abs(i - k))
			return (0);
		k--;
	}
	return (1);
}

void	queens(int i, int *board, int *cases)
{
	int	j;

	if (good(i, board))
	{
		if (i == 9)
		{
			(*cases)++;
			print_board(board);
		}
		else
		{
			j = 0;
			while (j <= 9)
			{
				board[i + 1] = j;
				queens(i + 1, board, cases);
				j++;
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	cases[1];

	i = 0;
	while (i < 10)
	{
		board[i++] = 0;
	}
	*cases = 0;
	queens(-1, board, cases);
	return (*cases);
}
