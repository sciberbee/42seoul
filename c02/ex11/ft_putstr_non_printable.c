/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:42:49 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 16:47:29 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_char_is_printable(char *ch);
void	ft_convert_npchar_to_hex_string(unsigned char npchar, char *hex_string);
void	ft_putstr_non_printable(char *str);

int	ft_char_is_printable(char *ch)
{
	int	yesorno;

	yesorno = 1;
	if ((*ch) < 32 || (*ch) == 127)
	{
		yesorno = 0;
	}
	return (yesorno);
}

void	ft_convert_npchar_to_hex_string(unsigned char npchar, char *hex_string)
{
	char	hex_table[16];
	int		i;
	int		charint;

	i = 0;
	charint = npchar;
	while (i < 10)
	{
		hex_table[i] = '0' + i;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		hex_table[10 + i] = 'a' + i;
		i++;
	}
	hex_string[0] = '\\';
	hex_string[1] = hex_table[charint / 16];
	hex_string[2] = hex_table[charint % 16];
	hex_string[3] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	char	hex_string[4];

	while (*str)
	{
		if (ft_char_is_printable(str))
		{
			write(1, str, 1);
		}
		else
		{
			ft_convert_npchar_to_hex_string((*str), hex_string);
			write(1, hex_string, 3);
		}
		str++;
	}
	return ;
}
