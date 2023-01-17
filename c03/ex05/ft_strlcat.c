/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:31:06 by sebang            #+#    #+#             */
/*   Updated: 2023/01/17 19:54:33 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char	buf[100000];
	int		idx;

	idx = 0;
	while ((*dest) && size)
	{
		buf[idx] = (*dest);
		dest++;
		idx++;
	}
	while ((*src) && size)
	{
		buf[idx] = (*src);
		src++;
		idx++;
	}
}
