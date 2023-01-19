/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:49:05 by sebang            #+#    #+#             */
/*   Updated: 2023/01/19 16:09:01 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

void	ft_print_pointer(void *addr)
{
	char			hex_string[16];
	int				i;
	long long		ptr;

	i = 0;
	ptr = (long long) addr;
	while (i < 16)
	{
		hex_string[15 - i] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
		i++;
	}
	write(1, hex_string, 16);
	write(1, ": ", 2);
}

void	ft_put_16byte_text(void *addr, char *textbuf)
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

void	*ft_print_nbyte_hex(void *addr, int n)
{
	unsigned char	byte;
	int				i;

	i = 0;
	while ((i < (n / 2)) && (i < 8))
	{
		byte = *(unsigned char *)(addr++);
		write(1, &"0123456789abcdef"[byte / 16], 1);
		write(1, &"0123456789abcdef"[byte % 16], 1);
		byte = *(unsigned char *)(addr++);
		write(1, &"0123456789abcdef"[byte / 16], 1);
		write(1, &"0123456789abcdef"[byte % 16], 1);
		write(1, " ", 1);
		i++;
	}
	if (n % 2 != 0)
	{
		byte = *(char *)(addr++);
		write(1, &"0123456789abcdef"[byte / 16], 1);
		write(1, &"0123456789abcdef"[byte % 16], 1);
	}
	return (addr);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*ret_addr;
	char	textbuf[16];

	ret_addr = addr;
	while (size >= 1)
	{
		ft_print_pointer(addr);
		ft_put_16byte_text(addr, textbuf);
		if (size >= 16)
		{
			addr = ft_print_nbyte_hex(addr, 16);
			write(1, textbuf, 16);
			size -= 16;
		}
		else
		{
			addr = ft_print_nbyte_hex(addr, size);
			write(1, "                                                  ",
				5 * ((16 - size) / 2) + 3 * (size % 2));
			write(1, textbuf, size);
			size = 0;
		}
		write(1, "\n", 1);
	}
	return (ret_addr);
}
