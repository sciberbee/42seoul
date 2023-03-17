/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:20:01 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 00:20:39 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	yesorno;

	yesorno = 1;
	while (*str)
	{
		if ((*str) < 'A' || (*str) > 'Z')
		{
			yesorno = 0;
		}
		str++;
	}
	return (yesorno);
}
