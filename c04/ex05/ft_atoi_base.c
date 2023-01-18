/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:11:32 by sebang            #+#    #+#             */
/*   Updated: 2023/01/18 22:55:04 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);
int	ft_validate_base_atoi(const char *base);
int	ft_char_idx_in_base(char ch, const char *base);
int	ft_make_result(char *str, char *base, int base_len);

int	ft_validate_base_atoi(const char *base)
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
	{
		ascii_table[i++] = 0;
	}
	while (*base)
	{
		if ((*base) == '+' || (*base) == '-')
			return (0);
		if (ascii_table[(int)(*base)] == 1)
			return (0);
		ascii_table[(int)(*base)] = 1;
		base++;
		base_len++;
	}
	return (base_len);
}

int	ft_char_idx_in_base(char ch, const char *base)
{
	int	i;

	i = 1;
	while (base[i - 1])
	{
		if (base[i - 1] == ch)
			return (i);
		i++;
	}
	return (0);
}

int	ft_make_result(char *str, char *base, int base_len)
{
	int	result;
	int	i;

	result = 0;
	i = ft_char_idx_in_base(*str, base);
	while (i)
	{
		result *= base_len;
		result += i - 1;
		str++;
		i = ft_char_idx_in_base(*str, base);
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_len;
	int		sign;

	base_len = ft_validate_base_atoi(base);
	if (!base_len)
		return (0);
	sign = 1;
	while (((*str) >= 9 && (*str) <= 13) || (*str) == 32)
	{
		str++;
	}
	while ((*str) == '+' || (*str) == '-')
	{
		if ((*str) == '-')
		{
			sign *= -1;
		}
		str++;
	}
	return (sign * ft_make_result(str, base, base_len));
}
