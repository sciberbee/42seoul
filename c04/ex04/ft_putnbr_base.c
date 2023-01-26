/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:19:39 by sebang            #+#    #+#             */
/*   Updated: 2023/01/26 21:26:56 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		ft_validate_base_putnbr(const char *base);

int	ft_validate_base_putnbr(const char *base)
{
	int	yesorno;
	int	base_len;
	int	i;
	int	ascii_table[256];

	if (!(*base) || !(*(base + 1)))
		return (0);
	yesorno = 1;
	base_len = 0;
	i = 0;
	while (i < 256)
	{
		ascii_table[i++] = 0;
	}
	while (*base)
	{
		if ((*base) == '+' || (*base) == '-')
			return (0);
		if (ascii_table[(int)(*base)] == 1)
			return (0);
		ascii_table[(int)(*base)] = 1;
		base++;
		base_len++;
	}
	return (base_len);
}

void	ft_put_zero(char *base)
{
	char	*zero_str;

	zero_str = malloc(sizeof(*zero_str) * 2);
	zero_str[0] = base[0];
	zero_str[1] = '\0';
	write(1, zero_str, 2);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	lnb;
	int			i;
	int			base_len;
	char		stack[50];

	base_len = ft_validate_base_putnbr(base);
	if (!base_len)
		return ;
	if (nbr == 0)
		ft_put_zero(base);
	lnb = nbr;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb = -lnb;
	}
	i = 0;
	while (lnb)
	{
		stack[i++] = *(base + (lnb % base_len));
		lnb = lnb / base_len;
	}
	i--;
	while (i >= 0)
		write(1, stack + (i--), 1);
}
