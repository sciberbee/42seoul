/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:26:29 by sebang            #+#    #+#             */
/*   Updated: 2023/01/30 13:26:47 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_display(char *path)
{
	int		fd;
	int		size;
	char	buf[1024];

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return ;
	}
	size = read(fd, buf, 1024);
	while (size != -1)
	{
		write(1, buf, size);
		size = read(fd, buf, 1024);
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc >= 3)
		write(1, "Too many arguments.\n", 20);
	else
		ft_display(argv[1]);
}
