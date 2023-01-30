/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:11:21 by sebang            #+#    #+#             */
/*   Updated: 2023/01/29 23:15:48 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*return_dest;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(dest) + ft_strlen(src) + 1;
	return_dest = malloc(sizeof(*return_dest) * len);
	i = 0;
	while (dest[i])
	{
		return_dest[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j])
	{
		return_dest[i] = src[j];
		j++;
		i++;
	}
	return_dest[i] = '\0';
	return (return_dest);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, " ", 1);
}

void	ft_putstr_bsp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, " ", 1);
	write(1, str, i);
}

void	ft_putstr_nsp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}
