/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:50 by jnoh              #+#    #+#             */
/*   Updated: 2022/01/25 17:34:44 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_strcpy_add_one(char *dest, char *str, int size, char chr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i++] = chr;
	dest[i] = '\0';
}

char	*ft_strdup_add_one(char *src, char chr)
{
	int		size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (size + 1 + 1));
	if (dest == 0)
		return (0);
	ft_strcpy_add_one(dest, src, size, chr);
	return (dest);
}
