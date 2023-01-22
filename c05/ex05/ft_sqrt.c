/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:32:47 by sebang            #+#    #+#             */
/*   Updated: 2023/01/22 14:41:49 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i <= 46340) && ((i * i) <= nb))
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}
