/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:33:53 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 14:41:27 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*ret_dest;
	int		copied_size;

	ret_dest = dest;
	copied_size = 0;
	while (*src && size >= 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
		copied_size++;
	}
	*dest = '\0';
	return (copied_size);
}
