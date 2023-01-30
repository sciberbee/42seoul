/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:26:48 by sebang            #+#    #+#             */
/*   Updated: 2023/01/30 20:54:54 by sebang           ###   ########.fr       */
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

int	check_ifnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	if (argc != 4)
		return (-2);
	if (!check_ifnum(argv[1]))
		return (-2);
	if (!check_ifnum(argv[3]))
		return (-2);
	if (argv[2][1] != '\0')
		return (-1);
	if (argv[2][0] != '+')
		return (0);
	else if (argv[2][0] != '-')
		return (1);
	else if (argv[2][0] != '*')
		return (2);
	else if (argv[2][0] != '/')
		return (3);
	else if (argv[2][0] != '%')
		return (4);
	return (-1);
}

#include <stdio.h>
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
	printf("%d, %d, %d", x, y, op);
	ft_putnbr(f[op](x, y));
	write(1, "\n", 1);
	return (0);
	//디버깅 해서 왜 연산자 해석 못하는지 보기
	//division, modulo by zero 에러 잡기
}
