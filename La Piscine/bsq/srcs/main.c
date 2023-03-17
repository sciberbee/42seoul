/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:37:33 by dongjlee          #+#    #+#             */
/*   Updated: 2022/01/27 11:31:02 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static t_game	*g_game;

char	*ft_read_line(int fd, int now_line)
{
	char	*this_line;

	this_line = ft_get_one_line(g_game, fd);
	if (g_game->find_eof == 2)
	{
		g_game->y = ft_strlen(this_line);
		g_game->find_eof = 0;
	}
	if ((now_line - 1 == g_game -> x) && (ft_strlen(this_line) == 0))
	{
		g_game -> find_eof = 1;
		free(this_line);
		return (0);
	}
	else if ((ft_strlen(this_line) != g_game -> y \
		|| now_line > g_game -> x) && g_game->find_eof != 2)
	{
		ft_error_map(g_game, this_line);
		return (0);
	}
	return (this_line);
}

int	ft_read_file(char *file_name, int mode)
{
	int		fd;
	int		i;

	fd = ft_open_file(g_game, file_name, mode);
	if (fd == -1)
		return (-1);
	if (ft_first_line(g_game, fd))
	{
		g_game->input_board = (char **)malloc(sizeof(char *) * (g_game->x + 1));
		i = 0;
		while (1)
		{
			g_game->input_board[i] = ft_read_line(fd, i + 1);
			if (g_game->input_board[i] == 0)
				break ;
			i++;
		}
	}
	close(fd);
	if (g_game->find_eof != -1)
		ft_do_logic(g_game);
	return (1);
}

void	ft_start(char *filename, int mode)
{
	int	fd;

	ft_init(g_game);
	ft_reset_print();
	fd = ft_read_file(filename, mode);
	if (fd != -1)
		ft_free_all(g_game);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	g_game = (t_game *)malloc(sizeof(t_game));
	if (g_game == 0)
		return (0);
	if (argc < 2)
	{
		ft_start("0", 0);
	}
	else
	{
		while (i < argc)
		{
			ft_start(argv[i], 1);
			i++;
		}
	}
	if (g_game != 0)
		free(g_game);
	return (0);
}
