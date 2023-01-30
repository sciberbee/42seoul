/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:34:33 by hayoon            #+#    #+#             */
/*   Updated: 2023/01/29 23:31:39 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_get_thous(char *dict, int start, int len);
char	**ft_get_hund(char *dict, int start, int len, int idx);
void	par_hund(char *dic, char **arr, int after_nl, int after_col);
char	ft_chk_dict(char *dict, int start, int len);
void	speak(char *str, char **arr1, char **arr2);
int		ft_chk_num(char *num);
int		chk_zero(char *num);
int		ft_str_len(char *num);
int		ft_is_dict(char *dictname);

int	len_of_dict(char *filename)
{
	char	buff[1024];
	int		fd;
	int		rest;
	int		len;

	len = 0;
	rest = 1024;
	fd = open(filename, O_RDONLY);
	while (rest > 0)
	{
		rest = read(fd, buff, rest);
		len += rest;
	}
	close(fd);
	return (len);
}

void	ft_read_dict(char *dictname, char *dict, int len)
{
	int	idx;
	int	fd;

	idx = 0;
	fd = open(dictname, O_RDONLY);
	if (fd > 1)
	{
		while (idx < len)
		{
			read(fd, &dict[idx], 1);
			idx++;
		}
	}
	close(fd);
}

void	ft_free(char *dict, char **hund, char **thous)
{
	int	idx;

	free(dict);
	idx = 1;
	while (idx < 102)
		free(hund[idx++]);
	free(hund);
	idx = 0;
	while (idx < 14)
		free(thous[idx++]);
	free(thous);
}

void	ft_parsing_dict(char *dict, int len, char *str)
{
	char	**hund;
	char	**thous;

	hund = ft_get_hund(dict, 0, len, 0);
	thous = ft_get_thous(dict, 0, len);
	if (!ft_chk_dict(dict, 0, len))
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	if (chk_zero(str))
	{
		write(1, hund[0], ft_str_len(hund[0]));
		write(1, "\n", 1);
	}
	else
		speak(str, hund, thous);
	ft_free(dict, hund, thous);
}

int	main(int argc, char **argv)
{
	char	*dictname;
	char	*dict;
	int		len;

	if (argc > 3 || argc == 1 || (ft_chk_num(argv[argc - 1]) == 0))
	{
		write(1, "error\n", 6);
		return (0);
	}
	dictname = "numbers.dict";
	if (argc == 3)
		dictname = argv[1];
	if ((ft_chk_num(argv[argc - 1]) == -1) || (!ft_is_dict(dictname)))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	len = len_of_dict(dictname);
	dict = (char *)malloc(sizeof(char) * (len + 1));
	dict[len] = 0;
	ft_read_dict(dictname, dict, len);
	ft_parsing_dict(dict, len, argv[argc - 1]);
	return (0);
}
