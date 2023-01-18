/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:31:06 by sebang            #+#    #+#             */
/*   Updated: 2023/01/18 19:35:08 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);
void			ft_strlcat_process_return(void);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size < d_len)
	{
		return (s_len + size);
	}
	i = 0;
	while (*(src + i) && d_len + (i + 1) + 1 <= size)
	{
		*(dest + d_len + i) = *(src + i);
		i++;
	}
	*(dest + d_len + i) = '\0';
	return (d_len + s_len);
}
