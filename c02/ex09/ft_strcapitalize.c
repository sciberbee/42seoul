/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:56:16 by sebang            #+#    #+#             */
/*   Updated: 2023/01/19 16:11:53 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

char	*ft_strlowcase_driver(char *str)
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

char	*ft_strcapitalize_driver(char *str, int found_word)
{
	char	*ret_str;

	ret_str = str;
	while (*str)
	{
		if (!found_word)
		{
			if (((*str) >= 'a' && (*str) <= 'z')
				|| ((*str) >= '0' && (*str) <= '9'))
			{
				if ((*str) >= 'a' && (*str) <= 'z')
					(*str) -= 32;
				found_word++;
			}
		}
		else
		{
			if (!((*str) >= 'a' && (*str) <= 'z')
				&& !((*str) >= '0' && (*str) <= '9'))
				found_word--;
		}
		str++;
	}
	return (ret_str);
}

char	*ft_strcapitalize(char *str)
{
	str = ft_strlowcase_driver(str);
	str = ft_strcapitalize_driver(str, 0);
	return (str);
}
