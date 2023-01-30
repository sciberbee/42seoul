/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:32:54 by sebang            #+#    #+#             */
/*   Updated: 2023/01/30 17:36:40 by sebang           ###   ########.fr       */
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

void	ft_tail_basic(char *path)
{
	int		fd;
	int		size;
	char	*str;
	char	buf[1024];

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "tail: ", 5);
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
	else if (argc == 2)
		ft_tail_basic(argv[1]);
	else if (argc == 4
		&& (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0'))
		ft_tail_c_option(argv[2], argv[3]);
	else
		write(1, "Too many arguments.\n", 20);
}
