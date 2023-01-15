/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:56:16 by sebang            #+#    #+#             */
/*   Updated: 2023/01/15 14:39:27 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
char	*ft_strlowcase_driver(char *str);
char	*ft_strcapitalize_driver(char *str, int found_word);

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
		while (!found_word)
		{
			if ((*str) >= 'a' && (*str) <= 'z')
			{
				(*str) -= 32;
				found_word++;
			}
			str++;
		}
		while (found_word)
		{
			if ((*str) < 'a' || (*str) > 'z')
			{
				found_word--;
			}
			str++;
		}
	}
	return (ret_str);
}

char	*ft_strcapitalize(char *str)
{
	int		found_word;

	str = ft_strlowcase_driver(str);
	found_word = 0;
	str = ft_strcapitalize_driver(str, found_word);
	return (str);
}
