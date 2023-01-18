/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:38:34 by sebang            #+#    #+#             */
/*   Updated: 2023/01/18 14:28:10 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int		subt;

	subt = 0;
	while (!subt && s1 && s2)
	{
		subt = (*s1) - (*s2);
		s1++;
		s2++;
	}
	return (subt);
}