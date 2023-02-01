/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:44:21 by jnoh              #+#    #+#             */
/*   Updated: 2022/01/27 11:22:52 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_open_file(t_game *game, char *file_name, int mode)
{
	int	fd;

	if (mode == 1)
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
		{
			ft_error_map(game, 0);
			return (-1);
		}
	}
	else
		fd = 0;
	return (fd);
}

int	ft_first_line_valid(char *check_charset)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (check_charset[i] < 32 || check_charset[i] > 126)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_first_line_empty(t_game *game, char *buf, int read_size)
{
	if (read_size == 0 || buf[0] == '\n')
	{
		ft_error_map(game, 0);
		return (1);
	}
	return (0);
}

int	ft_check_line_length(t_game *game, char *buf)
{
	if (buf[game->y - 1] != '\n')
	{
		ft_error_map(game, 0);
		return (1);
	}
	return (0);
}

int	ft_check_line_char(t_game *game, char *buf, int i)
{
	if (buf[i] != game->charset[0] && buf[i] != game->charset[1])
	{
		ft_error_map(game, 0);
		return (1);
	}
	return (0);
}
