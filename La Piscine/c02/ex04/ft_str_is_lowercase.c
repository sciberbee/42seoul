/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:07:08 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 00:19:04 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	yesorno;

	yesorno = 1;
	while (*str)
	{
		if ((*str) < 'a' || (*str) > 'z')
		{
			yesorno = 0;
		}
		str++;
	}
	return (yesorno);
}
