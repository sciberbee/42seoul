/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:17:49 by sebang            #+#    #+#             */
/*   Updated: 2023/01/20 22:19:38 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	n;

	n = 1;
	while (n < argc)
	{
		i = 0;
		while (argv[n][i])
		{
			i++;
		}
		write(1, argv[n], i);
		write(1, "\n", 1);
		n++;
	}
	return (0);
}
