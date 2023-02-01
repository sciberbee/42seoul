/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_some.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:35:30 by seunlee2          #+#    #+#             */
/*   Updated: 2023/02/01 14:50:20 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_chk_num(char *num)
{
	int	idx;

	idx = 0;
	while (num[idx])
	{
		if (!('0' <= num[idx] && num[idx] <= '9'))
			return (0);
		idx++;
	}
	if (idx > 38)
		return (-1);
	return (1);
}

int	chk_zero(char *num)
{
	int	idx;

	idx = 0;
	while (num[idx])
	{
		if (!(num[idx] == '0'))
			return (0);
		idx++;
	}
	return (1);
}

int	ft_str_len(char *num)
{
	int	idx;

	idx = 0;
	while (num[idx])
		idx++;
	return (idx);
}

int	ft_is_dict(char *dictname)
{
	int	fd;

	fd = open(dictname, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
