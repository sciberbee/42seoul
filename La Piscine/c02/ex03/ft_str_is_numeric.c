/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:04:22 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 00:19:39 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	yesorno;

	yesorno = 1;
	while (*str)
	{
		if ((*str) > '9' || (*str) < '0')
		{
			yesorno = 0;
		}
		str++;
	}
	return (yesorno);
}
