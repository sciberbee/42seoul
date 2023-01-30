/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_thous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:03:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/01/29 23:12:00 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	chk_zero(char *num);

void	ft_init(char **arr, int start, int end)
{
	while (start < end)
	{
		arr[start] = NULL;
		start++;
	}
}

int	ft_get_len(char *dict, int *start, int idx)
{
	int	cnt;
	int	len;

	cnt = 0;
	len = 0;
	while (*start < idx)
	{
		if (dict[*start] == '0')
			cnt++;
		else if (dict[*start] == 32 || dict[*start] == ':')
			break ;
		*start = *start + 1;
		len += 1;
	}
	if (len - 1 == cnt)
		return (cnt);
	else
		return (-1);
}

int	ft_get_name_size(char *dict, int *start, int idx)
{
	int	name_size;

	name_size = 0;
	while (*start < idx)
	{
		if (dict[*start] != 32 && dict[*start] != ':')
			name_size++;
		*start = *start + 1;
	}
	return (name_size);
}

char	*ft_get_thous_arr(char *dict, int *start, int idx)
{
	char	*thous_arr;
	int		thous_idx;
	int		name_size;

	name_size = ft_get_name_size(dict, start, idx);
	thous_arr = (char *) malloc(sizeof(char) * (name_size + 1));
	thous_idx = 0;
	while (name_size > 0)
	{
		thous_arr[thous_idx] = dict[idx - name_size];
		name_size--;
		thous_idx++;
	}
	thous_arr[thous_idx] = 0;
	return (thous_arr);
}

char	**ft_get_thous(char *dict, int start, int len)
{
	char	**thous;
	int		idx;
	int		cnt;

	idx = 0;
	thous = (char **) malloc(sizeof(char *) * 14);
	ft_init(thous, 0, 14);
	while (idx < len)
	{
		if (dict[idx] == '\n')
		{
			if (!(idx == start))
			{
				cnt = ft_get_len(dict, &start, idx);
				if (cnt >= 3 && cnt % 3 == 0 && cnt <= 37)
					thous[cnt / 3] = ft_get_thous_arr(dict, &start, idx);
				start = idx + 1;
			}
		}
		idx++;
	}
	return (thous);
}
