/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:23:51 by sebang            #+#    #+#             */
/*   Updated: 2023/01/29 16:23:28 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcpy_ex03(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*ret_str;
	int		i;
	int		total_len;

	if (size == 0)
	{
		str = malloc(1);
		return (str);
	}
	i = 0;
	total_len = 0;
	while (i < size)
		total_len += ft_strlen(strs[i++]) + ft_strlen(sep);
	str = malloc(sizeof(*str) * (total_len - ft_strlen(sep) + 1));
	ret_str = str;
	i = 0;
	while (i < size - 1)
	{
		str += ft_strcpy_ex03(str, strs[i++]);
		str += ft_strcpy_ex03(str, sep);
	}
	str += ft_strcpy_ex03(str, strs[i]);
	*str = '\0';
	return (ret_str);
}
