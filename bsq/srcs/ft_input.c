/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:51:46 by jnoh              #+#    #+#             */
/*   Updated: 2022/01/27 11:47:55 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_read_first_line(int fd)
{
	char	buf;
	char	*this_line;
	char	*tmp_line;
	int		read_size;
	int		i;

	i = -1;
	this_line = (char *)malloc(sizeof(char) * 1);
	this_line[0] = '\0';
	while (++i || 1)
	{
		tmp_line = ft_strdup(this_line);
		free(this_line);
		read_size = read(fd, &buf, 1);
		if (buf == '\n' || read_size == 0)
		{
			this_line = ft_strdup(tmp_line);
			free(tmp_line);
			break ;
		}
		this_line = ft_strdup_add_one(tmp_line, buf);
		free(tmp_line);
	}
	this_line[i] = '\0';
	return (this_line);
}

int	ft_first_line(t_game *game, int fd)
{
	char	*this_line;
	int		line_size;

	this_line = ft_read_first_line(fd);
	line_size = ft_strlen(this_line);
	if (line_size <= 3 || ft_is_overlap(&this_line[line_size - 3]) \
		|| !ft_is_all_number(this_line, this_line[line_size - 3]))
	{
		ft_error_map(game, this_line);
		return (0);
	}
	if (ft_first_line_valid(&this_line[line_size - 3]) == 0)
	{
		ft_error_map(game, this_line);
		return (0);
	}
	game->charset[0] = this_line[line_size - 3];
	game->charset[1] = this_line[line_size - 2];
	game->charset[2] = this_line[line_size - 1];
	this_line[line_size - 3] = '\0';
	game->x = ft_atoi(this_line);
	free(this_line);
	return (1);
}

char	*ft_get_one_line_first(t_game *game, int fd)
{
	int		i;
	int		read_size;
	char	*this_line;
	char	buf[100001];

	i = 0;
	while (1)
	{
		read_size = read(fd, buf + i, 1);
		if (ft_check_first_line_empty(game, buf, read_size))
			return (0);
		if (buf[i] == '\n' || read_size == 0)
		{
			buf[i] = '\0';
			this_line = ft_strdup(buf);
			break ;
		}
		if (buf[i] != game->charset[0] && buf[i] != game->charset[1])
		{
			ft_error_map(game, 0);
			return (0);
		}
		i++;
	}
	return (this_line);
}

char	*ft_get_one_line_other(t_game *game, int fd)
{
	int		i;
	int		read_size;
	char	buf[100001];

	i = -1;
	while (++i || 1)
	{
		read_size = read(fd, buf, game->y + 1);
		while (i < read_size && i < game->y)
		{
			if (ft_check_line_char(game, buf, i))
				return (0);
			i++;
		}
		if (buf[i] == '\n' || read_size == 0)
		{
			buf[i] = '\0';
			return (ft_strdup(buf));
		}
		if (ft_check_line_length(game, buf))
			return (0);
	}
	return (0);
}

char	*ft_get_one_line(t_game *game, int fd)
{
	char	*this_line;

	if (game->find_eof == 2)
		this_line = ft_get_one_line_first(game, fd);
	else
		this_line = ft_get_one_line_other(game, fd);
	return (this_line);
}
