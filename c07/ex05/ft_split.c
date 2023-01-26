/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:50:35 by sebang            #+#    #+#             */
/*   Updated: 2023/01/26 11:57:25 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	char_in_set(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (char_in_set(str[i + 1], charset) && !char_in_set(str[i], charset))
			words++;
		i++;
	}
	return (words);
}

void	wordcpy(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (!char_in_set(from[i], charset))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	put_arr(char *str, char **arr, char *charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (char_in_set(str[i], charset))
			i++;
		else
		{
			j = 0;
			while (!char_in_set(str[i + j], charset))
				j++;
			arr[word] = malloc(sizeof (char) * (j + 1));
			wordcpy(arr[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	char	**ret_arr;

	count = count_words(str, charset);
	ret_arr = malloc(sizeof (char *) * (words + 1));
	ret_arr[words] = 0;
	put_arr(str, ret_arr, charset);
	return (ret_arr);
}
