/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:53:30 by seunlee2          #+#    #+#             */
/*   Updated: 2023/01/29 23:32:25 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_func(char *str, int start, int end)
{
	int	num;

	num = 0;
	while (start < end)
	{
		num = num * 10 + (str[start] - '0');
		start++;
	}
	return (num);
}

int	ft_isspace(char *str, int len)
{
	while (str[len])
	{
		if (!(str[len] == '\t' || str[len] == '\n' || str[len] == '\v'
				|| str[len] == '\f' || str[len] == '\r' || str[len] == ' '))
			break ;
		len++;
	}
	return (len);
}

int	ft_issign(char *str, int str_len, int *minus)
{
	*minus = 1;
	while (str[str_len])
	{
		if (str[str_len] == '-')
			*minus *= -1;
		else if (!(str[str_len] == '+'))
			break ;
		str_len++;
	}
	return (str_len);
}

int	ft_atoi(char *str)
{
	int	minus;
	int	str_len;
	int	start_idx;

	str_len = ft_isspace(str, 0);
	str_len = ft_issign(str, str_len, &minus);
	start_idx = str_len;
	while (str[str_len])
	{
		if (!('0' <= str[str_len] && str[str_len] <= '9'))
			break ;
		str_len++;
	}
	return (minus * ft_atoi_func(str, start_idx, str_len));
}
