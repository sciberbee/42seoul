/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:49:05 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 18:17:30 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_print_memory(void *addr, unsigned int size);
void	ft_print_pointer_to_hex_string(void *addr);
void	ft_print_16byte_to_hex(void *addr);

char	g_hex_table[16];

void	ft_print_pointer_to_hex_string(void *addr)
{
	char			hex_string[16];
	int				i;
	unsigned int	ptr;

	i = 0;
	ptr = (int) addr;
	while (i < 16)
	{
		hex_string[15 - i] = g_hex_table[ptr % 16];
		ptr /= 16;
		i++;
	}
	write(1, hex_string, 16);
	write(1, ": ", 2);
}

void	ft_print_16byte_to_hex(void *addr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 8)
	{
		while (i < 4)
		{
			write(1, &g_hex_table[(*(unsigned int *)addr) / 16], 1);
			write(1, &g_hex_table[(*(unsigned int *)addr) % 16], 1);
			i++;
		}
		write(1, " ", 1);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*ret_addr;

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
	ret_addr = addr;
	ft_print_pointer_to_hex_string(addr);
	ft_print_16byte_to_hex(addr);
	return (ret_addr);
}
