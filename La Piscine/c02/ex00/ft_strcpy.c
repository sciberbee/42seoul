/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:30:42 by sebang            #+#    #+#             */
/*   Updated: 2023/01/14 21:35:46 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	while (*(src + len) != '\0')
	{
		len++;
	}
	len++;
	i = 0;
	while (i < len)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}
