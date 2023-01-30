/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:14:47 by sebang            #+#    #+#             */
/*   Updated: 2023/01/30 15:29:47 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_cat_open(char *path)
{
	int		fd;
	int		size;
	char	*str;
	char	buf[1024];

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "cat: ", 5);
		str = basename(path);
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
		str = strerror(errno);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		return ;
	}
	size = read(fd, buf, 1024);
	while (size)
	{
		write(1, buf, size);
		size = read(fd, buf, 1024);
	}
	close(fd);
	return ;
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else
	{
		i = 1;
		while (i <= argc - 1)
		{
			ft_cat_open(argv[i]);
			i++;
		}
	}
}
