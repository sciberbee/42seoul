/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:48:15 by sebang            #+#    #+#             */
/*   Updated: 2023/01/17 19:07:09 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	subt;

	subt = 0;
	while (!subt && s1 && s2 && n)
	{
		subt = (*s1) - (*s2);
		s1++;
		s2++;
		n--;
	}
	return (subt);
}
