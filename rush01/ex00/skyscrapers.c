/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:17:08 by sebang            #+#    #+#             */
/*   Updated: 2023/01/22 17:55:13 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_col_up(int *board, int *clues, int col_no);
int	check_col_down(int *board, int *clues, int col_no);
int	check_row_left(int *board, int *clues, int row_no);
int	check_row_right(int *board, int *clues, int row_no);
int	check_all_clue(int *board, int *clues);

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

void	skyscrapers(int i, int *board, int *clues, int *printed)
{
	int	j;

	if (no_duplicate(i, board) && !(*printed))
	{
		if (i == 15)
		{
			if (check_all_clue(board, clues))
			{
				print_board(board);
				(*printed)++;
			}
		}
		else
		{
			j = 1;
			while (j <= 4)
			{
				board[i + 1] = j;
				skyscrapers(i + 1, board, clues, printed);
				j++;
			}
		}
	}
}

void	ft_four_skyscrapers_puzzle(char *clue_string)
{
	int	board[16];
	int	clues[16];
	int	i;
	int	printed[1];

	i = 0;
	while (clue_string[i])
		i++;
	if (i != 31)
	{
		write(1, "Error\n", 6);
		return ;
	}
	i = 0;
	while (i < 16)
	{
		clues[i] = (int)(clue_string[2 * i] - '0');
		i++;
	}
	*printed = 0;
	skyscrapers(-1, board, clues, printed);
	if (!(*printed))
		write(1, "Error\n", 6);
}

//Requires very thorough input verification.
int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if ((i % 2 == 0) && (argv[1][i] > '4' || argv[1][i] < '1'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if ((i % 2 != 0) && (argv[1][i] != ' '))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	ft_four_skyscrapers_puzzle(argv[1]);
	return (0);
}
