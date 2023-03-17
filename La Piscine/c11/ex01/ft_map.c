/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:33:51 by sebang            #+#    #+#             */
/*   Updated: 2023/01/30 17:35:36 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret_tab;

	ret_tab = malloc(sizeof(*ret_tab) * length);
	i = 0;
	while (i < length)
	{
		ret_tab[i] = f(tab[i]);
		i++;
	}
	return (ret_tab);
}
