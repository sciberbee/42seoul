/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:49:05 by sebang            #+#    #+#             */
/*   Updated: 2023/01/17 18:37:47 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	ft_print_pointer(void *addr);
void	ft_print_put_2byte(void *addr);
void	ft_put_16byte_textbuf(void *addr, char *textbuf);

char	g_hex_table[16];

void	ft_print_pointer(void *addr)
{
	char			hex_string[16];
	int				i;
	long long		ptr;

	i = 0;
	ptr = (long long) addr;
	while (i < 16)
	{
		hex_string[15 - i] = g_hex_table[ptr % 16];
		ptr /= 16;
		i++;
	}
	write(1, hex_string, 16);
	write(1, ": ", 2);
}

void	ft_print_put_2byte(void *addr)
{
	char	byte;
	char	buf[5];

	byte = *(char *)addr;
	buf[1] = g_hex_table[byte % 16];
	byte /= 16;
	buf[0] = g_hex_table[byte % 16];
	byte /= 16;
	addr++;
	byte = *(char *)addr;
	buf[3] = g_hex_table[byte % 16];
	byte /= 16;
	buf[2] = g_hex_table[byte % 16];
	byte /= 16;
	buf[4] = ' ';
	write(1, buf, 5);
	addr++;
}

void	fill_g_hex_table(void)
{
	g_hex_table[0] = '0';
	g_hex_table[1] = '1';
	g_hex_table[2] = '2';
	g_hex_table[3] = '3';
	g_hex_table[4] = '4';
	g_hex_table[5] = '5';
	g_hex_table[6] = '6';
	g_hex_table[7] = '7';
	g_hex_table[8] = '8';
	g_hex_table[9] = '9';
	g_hex_table[10] = 'a';
	g_hex_table[11] = 'b';
	g_hex_table[12] = 'c';
	g_hex_table[13] = 'd';
	g_hex_table[14] = 'e';
	g_hex_table[15] = 'f';
}

void	ft_put_16byte_textbuf(void *addr, char *textbuf)
{
	int		i;
	char	*charaddr;

	i = 0;
	charaddr = (char *)addr;
	while (i < 16)
	{
		if ((*charaddr) < 32 || (*charaddr) == 127)
		{
			textbuf[i] = '.';
		}
		else
		{
			textbuf[i] = *charaddr;
		}
		charaddr++;
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*ret_addr;
	char	textbuf[16];
	int		loop_var;
	int		i;

	fill_g_hex_table();
	ret_addr = addr;
	while (size > 1)
	{
		ft_print_pointer(addr);
		ft_put_16byte_textbuf(addr, textbuf);
		loop_var = 8;
		while (size > 1 && loop_var > 0)
		{
			ft_print_put_2byte(addr);
			addr = addr + 2;
			size = size - 2;
			loop_var--;
		}
		write(1, textbuf, 16);
		write(1, "\n", 1);
	}
	return (ret_addr);
}
