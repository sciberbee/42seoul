/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speak.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:45:05 by sebang            #+#    #+#             */
/*   Updated: 2023/01/29 23:37:08 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	**parse_arr1(void);
char	**parse_arr2(void);
void	ft_putstr(char *str);
void	ft_putstr_bsp(char *str);
void	ft_putstr_nsp(char *str);
void	process_last(int last);
int		speak_n00(char **arr, char n, int last);
void	speak_last2_general(char **arr, char *nbr_str);
int		speak_to999(char *nbr_str, int last, char **arr);
int		zero_till_end(char *str);

char	*replenish_str(char *str)
{
	if (ft_strlen(str) % 3 == 1)
		str = ft_strcat("00", str);
	else
		str = ft_strcat("0", str);
	return (str);
}

void	speak(char *str, char **arr1, char **arr2)
{
	int		pow1000;

	free(arr1[0]);
	arr1[0] = "";
	pow1000 = ft_strlen(str) / 3;
	if (ft_strlen(str) % 3)
		str = replenish_str(str);
	else
		pow1000--;
	while (pow1000 >= 1)
	{
		if (!speak_to999(str, 0, arr1))
		{
			if (zero_till_end(str + 3))
				ft_putstr_nsp(arr2[pow1000]);
			else
				ft_putstr(arr2[pow1000]);
		}
		str += 3;
		pow1000--;
	}
	speak_to999(str, 1, arr1);
}
