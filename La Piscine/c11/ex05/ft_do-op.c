/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do-op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:26:48 by sebang            #+#    #+#             */
/*   Updated: 2023/01/31 15:59:45 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		add(int x, int y);
int		sub(int x, int y);
int		mul(int x, int y);
int		div(int x, int y);
int		mod(int x, int y);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int	check_arg(int argc, char **argv)
{
	if (argc != 4)
		return (-2);
	if (argv[2][1] != '\0')
		return (-1);
	if (argv[2][0] == '+')
		return (0);
	else if (argv[2][0] == '-')
		return (1);
	else if (argv[2][0] == '*')
		return (2);
	else if (argv[2][0] == '/')
		return (3);
	else if (argv[2][0] == '%')
		return (4);
	return (-1);
}

int	chk_divzero(int op, int y)
{
	if (op == 3 && y == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (-1);
	}
	if (op == 4 && y == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	op;
	int	x;
	int	y;
	int	(*f[5])(int x, int y);

	op = check_arg(argc, argv);
	if (op == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	else if (op == -2)
		return (0);
	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	if (chk_divzero(op, y) == -1)
		return (0);
	ft_putnbr(f[op](x, y));
	write(1, "\n", 1);
	return (0);
}
