/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:17:08 by jnoh              #+#    #+#             */
/*   Updated: 2022/01/27 09:41:28 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**ft_malloc_int_array(int x, int y)
{
	int	i;
	int	j;
	int	**ret;

	ret = (int **) malloc((x + 1) * sizeof(int *));
	if (ret == 0)
		return (0);
	i = -1;
	while (++i < x)
	{
		ret[i] = (int *) malloc((y + 1) * sizeof(int));
		if (ret[i] == 0)
			return (0);
		j = 0;
		while (j < y)
			ret[i][j++] = 0;
	}
	return (ret);
}

void	ft_free_all(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->x)
	{
		if (game->input_board != 0 && game->input_board[i] != 0)
			free(game->input_board[i]);
		if (game->result_board != 0 && game->result_board[i] != 0)
			free(game->result_board[i]);
		i++;
	}
	if (game->input_board != 0)
		free(game->input_board);
	if (game->result_board != 0)
		free(game->result_board);
}

void	ft_init(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->find_eof = 2;
}
