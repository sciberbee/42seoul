/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:52:48 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 00:02:21 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int	yesorno;

	yesorno = 1;
	while (*str)
	{
		if ((*str) < 'A')
		{
			yesorno = 0;
		}
		if ((*str) > 'Z' && (*str) < 'a')
		{
			yesorno = 0;
		}
		if ((*str) > 'z')
		{
			yesorno = 0;
		}
		str++;
	}
	return (yesorno);
}
