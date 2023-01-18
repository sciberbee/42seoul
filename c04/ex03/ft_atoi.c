/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:52:04 by sebang            #+#    #+#             */
/*   Updated: 2023/01/18 22:35:11 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
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
	while ((*str) >= '0' && (*str) <= '9')
	{
		result *= 10;
		result += (*str) - '0';
		str++;
	}
	return (sign * result);
}
