/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:14:10 by sebang            #+#    #+#             */
/*   Updated: 2023/01/22 18:25:25 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
		return (0);
	arr = malloc(sizeof(*arr) * (max - min));
	i = 0;
	while (i < (max - min))
	{
		arr[i] = min + 1;
		i++;
	}
	return (arr);
}
