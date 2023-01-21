/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:17:08 by sebang            #+#    #+#             */
/*   Updated: 2023/01/21 22:33:56 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_board(int	*board)
{
	int		i;
	char	ch;

	i = 0;
	while (i < 16)
	{
		ch = '0' + board[i];
		write(1, &ch, 1);
		i++;
		if (i % 4 != 0)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
	}
}

int	check_col(int *board, int *clues, int col_no)
{
	int	seen1;
	int	seen2;
	int	idx;
	int	curr;

	idx = col_no;
	seen1 = 1;
	curr = board[idx];
	while (idx <= 12 + col_no)
	{
		if (board[idx] > curr)
		{
			seen1++;
			curr = board[idx];
		}
		idx += 4;
	}
	seen2 = 1;
	idx -= 4;
	curr = board[idx];
	while (idx >= col_no)
	{
		if (board[idx] > curr)
		{
			seen2++;
			curr = board[idx];
		}
		idx -= 4;
	}
	return (seen1 == clues[col_no] && seen2 == clues[4 + col_no]);
}

int	check_row(int *board, int *clues, int row_no)
{
	int	seen1;
	int	seen2;
	int	idx;
	int	curr;

	idx = 4 * row_no;
	seen1 = 1;
	curr = board[idx];
	while (idx <= 3 + 4 * row_no)
	{
		if (board[idx] > curr)
		{
			seen1++;
			curr = board[idx];
		}
		idx += 1;
	}
	seen2 = 1;
	idx -= 1;
	curr = board[idx];
	while (idx >= 4 * row_no)
	{
		if (board[idx] > curr)
		{
			seen2++;
			curr = board[idx];
		}
		idx -= 1;
	}
	return (seen1 == clues[8 + row_no] && seen2 == clues[12 + row_no]);
}

int	no_duplicate(int i, int *board)
{
	int	k;

	if (i == -1)
		return (1);
	if (i == 0)
		return (1);
	k = i - 1;
	while (k >= 0)
	{
		if ((k / 4 == i / 4) && (board[k] == board[i]))
			return (0);
		if ((k % 4 == i % 4) && (board[k] == board[i]))
			return (0);
		k--;
	}
	return (1);
}

int	check_all_clue(int *board, int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_row(board, clues, i))
			return (0);
		if (!check_col(board, clues, i))
			return (0);
		i++;
	}
	return (1);
}

void	skyscrapers(int i, int *board, int *clues)
{
	int	j;

	if (no_duplicate(i, board))
	{
		if (i == 15)
		{
			if (check_all_clue(board, clues))
				print_board(board);
		}
		else
		{
			j = 1;
			while (j <= 4)
			{
				board[i + 1] = j;
				skyscrapers(i + 1, board, clues);
				j++;
			}
		}
	}
}

void	ft_four_skyscrapers_puzzle(int *clues)
{
	int	board[16];
	int	i;

	i = 0;
	while (i < 16)
		board[i++] = 0;
	skyscrapers(-1, board, clues);
}

//Requires very thorough input verification.
int	main(int argc, char **argv)
{
	int	i;
	int	clues[16];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 16)
	{
		clues[i] = (int)(argv[1][2 * i] - '0');
		i++;
	}
	ft_four_skyscrapers_puzzle(clues);
	return (0);
}
