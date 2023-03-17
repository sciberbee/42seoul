/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:58:19 by sebang            #+#    #+#             */
/*   Updated: 2023/01/23 10:46:21 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb);

int	ft_is_prime_ex07(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if ((nb % 2 == 0) || (nb % 3 == 0))
		return (0);
	i = 5;
	while ((i * i) <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	if (2147483629 < nb && nb <= 2147483647)
		return (2147483647);
	while (!ft_is_prime_ex07(nb) && nb < 2147483647)
	{
		nb++;
	}
	return (nb);
}
