/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:52:58 by sebang            #+#    #+#             */
/*   Updated: 2023/01/11 12:46:06 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // write

void	ft_putchar(char c);

int	main(void)
{
	ft_putchar('f');
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
