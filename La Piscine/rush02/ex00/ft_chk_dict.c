/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:03:39 by seunlee2          #+#    #+#             */
/*   Updated: 2023/01/29 23:11:37 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_num(char *dict, int *start, int idx)
{
	if (!('0' <= dict[*start] && dict[*start] <= '9'))
		return (0);
	while (*start < idx)
	{
		if (dict[*start] == 32 || dict[*start] == ':')
			return (1);
		else if (!('0' <= dict[*start] && dict[*start] <= '9'))
			return (0);
		*start = *start + 1;
	}
	return (1);
}

int	ft_is_space(char *dict, int *start)
{
	if (dict[*start] == ':')
		return (1);
	while (dict[*start] != ':')
	{
		if (!(dict[*start] == 32))
			return (0);
		*start = *start + 1;
	}
	return (1);
}

int	ft_chk_colon_nonprint(char *dict, int start, int idx)
{
	int	chk;

	chk = 0;
	while (start < idx)
	{
		if (!(32 <= dict[start] && dict[start] <= 126))
			return (0);
		if (chk == 2)
			return (0);
		if (dict[start] == ':')
			chk++;
		start++;
	}
	if (chk == 1)
		return (1);
	else
		return (0);
}

char	ft_chk_dict(char *dict, int start, int len)
{
	int		idx;
	int		row;

	idx = 0;
	row = 0;
	while (idx < len)
	{
		if (dict[idx] == '\n')
		{
			row++;
			if (!(idx == start))
				if (!ft_chk_colon_nonprint(dict, start, idx)
					|| !ft_is_num(dict, &start, idx)
					|| !ft_is_space(dict, &start))
					return (0);
			start = idx + 1;
		}
		idx++;
	}
	if (row < 41)
		return (0);
	return (1);
}
