/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:04:56 by jnoh              #+#    #+#             */
/*   Updated: 2022/01/27 10:46:14 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	g_isprinted;

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
}

void	ft_print_ans(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	size;

	if (g_isprinted)
		return ;
	if (x < 0 || y < 0)
		return ;
	size = game->result_board[x][y];
	i = 0;
	while (i < game->x)
	{
		j = 0;
		while (j < game->y)
		{
			if (i >= x && i < x + size && j >= y && j < y + size)
				write(1, &(game->charset[2]), 1);
			else
				write(1, &(game->input_board[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	g_isprinted = 1;
}

void	ft_print_board(t_game *game)
{
	int	i;
	int	j;

	if (g_isprinted)
		return ;
	i = 0;
	while (i < game->x)
	{
		j = 0;
		while (j < game->y)
		{
			write(1, &(game->input_board[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	g_isprinted = 1;
}

void	ft_error_map(t_game *game, void *to_free)
{
	if (!g_isprinted)
		write(2, "map error\n", 10);
	if (to_free != 0)
		free(to_free);
	g_isprinted = 1;
	game->find_eof = -1;
}

void	ft_reset_print(void)
{
	g_isprinted = 0;
}
