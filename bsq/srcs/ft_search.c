/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:40:11 by jnoh              #+#    #+#             */
/*   Updated: 2022/01/26 18:45:49 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static t_game	*g_game;

int	ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int	ft_get(int x, int y)
{
	if (x >= g_game->x || y >= g_game->y)
		return (0);
	return (g_game->result_board[x][y]);
}

void	ft_search(void)
{
	int	i;
	int	j;

	i = g_game->x - 1;
	while (i >= 0)
	{
		j = g_game->y - 1;
		while (j >= 0)
		{
			if (g_game->input_board[i][j] != g_game->charset[1])
			{
				g_game->result_board[i][j] = 1 + ft_min(ft_get(i + 1, j), \
					ft_get(i, j + 1), ft_get(i + 1, j + 1));
				if (g_game->ans[0] <= g_game->result_board[i][j])
				{
					g_game->ans[0] = g_game->result_board[i][j];
					g_game->ans[1] = i;
					g_game->ans[2] = j;
				}
			}
			j--;
		}
		i--;
	}
}

void	ft_do_logic(t_game *game)
{
	int	i;

	g_game = game;
	g_game->ans[0] = -1;
	g_game->ans[1] = g_game->x - 1;
	g_game->ans[2] = g_game->y - 1;
	g_game->result_board = ft_malloc_int_array(g_game->x, g_game->y);
	i = 0;
	while (i < g_game->x)
	{
		if (g_game->input_board[i][g_game->y - 1] != g_game->charset[1])
			g_game->result_board[i][g_game->y - 1] = 1;
		i++;
	}
	i = 0;
	while (i < g_game->y)
	{
		if (g_game->input_board[g_game->x - 1][i] != g_game->charset[1])
			g_game->result_board[g_game->x - 1][i] = 1;
		i++;
	}
	ft_search();
	ft_print_ans(g_game, g_game->ans[1], g_game->ans[2]);
	ft_print_board(g_game);
}
