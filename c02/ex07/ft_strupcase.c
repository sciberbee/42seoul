/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:26:54 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 00:29:39 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	char	*ret_str;

	ret_str = str;
	while (*str)
	{
		if ((*str) >= 'a' && (*str) <= 'z')
		{
			(*str) -= 32;
		}
		str++;
	}
	return (ret_str);
}
