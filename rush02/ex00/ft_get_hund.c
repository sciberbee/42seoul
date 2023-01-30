/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hund.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:34:15 by seunlee2          #+#    #+#             */
/*   Updated: 2023/01/29 23:11:55 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_get_name_size(char *dict, int *start, int idx);
int		ft_atoi(char *str);
void	ft_init(char **arr, int start, int end);

int	ft_get_arr_len(char *dict, int *start, int idx)
{
	int	len;
	int	arr_idx;

	arr_idx = *start;
	len = 0;
	while (arr_idx < idx)
	{
		if (dict[arr_idx] != 32 && dict[arr_idx] != ':')
		{
			arr_idx++;
			len++;
		}
		else
			break ;
	}
	return (len);
}

char	*ft_get_str(char *dict, int *start, int idx)
{
	char	*arr;
	int		len;

	len = ft_get_arr_len(dict, start, idx);
	if (len > 3)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (*start < idx)
	{
		if (dict[*start] != 32 && dict[*start] != ':')
			arr[len] = dict[*start];
		else
			break ;
		*start = *start + 1;
		len++;
	}
	arr[len] = 0;
	return (arr);
}

char	*ft_get_arr(char *dict, int *start, int idx)
{
	char	*hund_arr;
	int		hund_idx;
	int		name_size;

	name_size = ft_get_name_size(dict, start, idx);
	hund_arr = (char *) malloc(sizeof(char) * (name_size + 1));
	hund_idx = 0;
	while (name_size > 0)
	{
		hund_arr[hund_idx] = dict[idx - name_size];
		name_size--;
		hund_idx++;
	}
	hund_arr[hund_idx] = 0;
	return (hund_arr);
}

char	**ft_get_hund(char *dict, int start, int len, int idx)
{
	char	**hund;
	char	*arr;

	hund = (char **) malloc(sizeof(char *) * 102);
	ft_init(hund, 0, 102);
	while (idx < len)
	{
		if (dict[idx] == '\n')
		{
			if (!(idx == start))
			{
				arr = ft_get_str(dict, &start, idx);
				if (arr != NULL)
				{
					if (ft_atoi(arr) <= 19)
						hund[ft_atoi(arr)] = ft_get_arr(dict, &start, idx);
					else if (ft_atoi(arr) % 10 == 0 && ft_atoi(arr) <= 100)
						hund[ft_atoi(arr)] = ft_get_arr(dict, &start, idx);
				}
			}
			start = idx + 1;
		}
		idx++;
	}
	return (hund);
}
