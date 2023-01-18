/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:41:50 by sebang            #+#    #+#             */
/*   Updated: 2023/01/18 19:28:37 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	copy;
	unsigned int	check_n;

	check_n = n;
	copy = 0;
	while (*(src + copy) != '\0')
	{
		copy++;
	}
	copy++;
	i = 0;
	while (i < copy && i < n)
	{
		*(dest + i) = *(src + i);
		i++;
		check_n--;
	}
	while (check_n > 0)
	{
		*(dest + i) = '\0';
		i++;
		check_n--;
	}
	return (dest);
}
