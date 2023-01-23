/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:56:42 by sebang            #+#    #+#             */
/*   Updated: 2023/01/23 18:57:04 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
