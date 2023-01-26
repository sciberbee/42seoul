/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:42:52 by sebang            #+#    #+#             */
/*   Updated: 2023/01/26 12:53:06 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_lf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, idx);
	write(1, "\n", 1);
}

void	ft_putnbr_lf(int nb)
{
	char	stack[10];
	int		i;

	if (nb == 0)
		write(1, "0", 1);
	i = 0;
	while (nb)
	{
		stack[i++] = '0' + (nb % 10);
		nb = nb / 10;
	}
	i--;
	while (i >= 0)
	{
		write(1, stack + (i--), 1);
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par);

void	ft_show_tab(struct s_stock_str *par)
{
	int	len;
	int	i;

	len = 0;
	while (par[len].str)
		len++;
	i = 0;
	while (i < len)
	{
		ft_putstr_lf(par[i].str);
		ft_putnbr_lf(par[i].size);
		ft_putstr_lf(par[i].copy);
	}
}
