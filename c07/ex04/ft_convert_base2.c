/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:56:42 by sebang            #+#    #+#             */
/*   Updated: 2023/01/27 10:47:23 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_validate_base(const char *base)
{
	int	yesorno;
	int	base_len;
	int	i;
	int	ascii_table[256];

	if (!(*base) || !(*(base + 1)))
		return (0);
	yesorno = 1;
	base_len = 0;
	i = 0;
	while (i < 256)
		ascii_table[i++] = 0;
	while (*base)
	{
		if ((*base) == '+' || (*base) == '-'
			|| (*base) == ' ' || ((*base) >= 9 && (*base) <= 13))
			return (0);
		if (ascii_table[(unsigned char)(*base)] == 1)
			return (0);
		ascii_table[(unsigned char)(*base)] = 1;
		base++;
		base_len++;
	}
	return (base_len);
}

char	*ft_zero_string(char *base_to)
{
	char	*zero_str;

	zero_str = malloc(sizeof(*zero_str) * 2);
	zero_str[0] = base_to[0];
	zero_str[1] = '\0';
	return (zero_str);
}
