/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speak_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:57:12 by sebang            #+#    #+#             */
/*   Updated: 2023/01/29 23:30:31 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putstr_bsp(char *str);
void	ft_putstr_nsp(char *str);

void	process_last(int last)
{
	if (!last)
		write(1, " ", 1);
	else
		write(1, "\n", 1);
	return ;
}

int	speak_n00(char **arr, char n, int last)
{
	if (n == '0')
	{	
		if (last)
			write(1, "\n", 1);
		return (1);
	}
	else
	{
		ft_putstr(arr[n - '0']);
		ft_putstr_nsp(arr[100]);
		process_last(last);
		return (0);
	}
}

void	speak_last2_general(char **arr, char *nbr_str)
{
	if (nbr_str[1] != '0')
		ft_putstr_nsp(arr[(nbr_str[1] - '0') * 10]);
	if (nbr_str[2] != '0' && nbr_str[1] != '0')
		ft_putstr_bsp(arr[nbr_str[2] - '0']);
	else if (nbr_str[2] != '0' && nbr_str[1] == '0')
		ft_putstr_nsp(arr[nbr_str[2] - '0']);
}

int	speak_to999(char *nbr_str, int last, char **arr)
{
	if (nbr_str[1] == '0' && nbr_str[2] == '0')
	{
		return (speak_n00(arr, nbr_str[0], last));
	}
	if (nbr_str[0] != '0')
	{
		ft_putstr(arr[nbr_str[0] - '0']);
		ft_putstr(arr[100]);
	}
	if (nbr_str[1] == '1')
		ft_putstr_nsp(arr[(nbr_str[2] - '0') + 10]);
	else
		speak_last2_general(arr, nbr_str);
	process_last(last);
	return (0);
}

int	zero_till_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
