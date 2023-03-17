/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:42:49 by sebang            #+#    #+#             */
/*   Updated: 2023/01/28 17:48:12 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

void	ft_putstr_non_printable(char *str)
{
	char	hex_string[3];

	hex_string[0] = '\\';
	while (*str)
	{
		if ((*str) < 32 || (*str) == 127)
		{
			hex_string[1] = "0123456789abcdef"[(unsigned char)(*str) / 16];
			hex_string[2] = "0123456789abcdef"[(unsigned char)(*str) % 16];
			write(1, hex_string, 3);
		}
		else
		{
			write(1, str, 1);
		}
	}
	return ;
}
