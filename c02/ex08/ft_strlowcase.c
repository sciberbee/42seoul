/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:28:55 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 00:30:22 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	char	*ret_str;

	ret_str = str;
	while (*str)
	{
		if ((*str) >= 'A' && (*str) <= 'Z')
		{
			(*str) += 32;
		}
		str++;
	}
	return (ret_str);
}
