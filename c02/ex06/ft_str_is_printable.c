/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:20:56 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 00:30:28 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	yesorno;

	yesorno = 1;
	while (*str)
	{
		if ((*str) < 33 || (*str) == 127)
		{
			yesorno = 0;
		}
		str++;
	}
	return (yesorno);
}
