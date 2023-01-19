/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:28:56 by sebang            #+#    #+#             */
/*   Updated: 2023/01/19 16:41:25 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

int	ft_cmp_driver(const char *s1, const char *s2)
{
	while ((*s1) && (*s2))
	{
		if ((*s1) != (*s2))
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s2 == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*str == '\0' && *to_find == '\0')
		return (str);
	while (*str)
	{
		if (ft_cmp_driver(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return (0);
}
