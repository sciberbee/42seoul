/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:33:53 by sebang            #+#    #+#             */
/*   Updated: 2023/01/19 11:35:26 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int				src_len;
	unsigned int	i;

	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	i = 0;
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
	{
		dest[i] = '\0';
	}
	return (src_len);
}
