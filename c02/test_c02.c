/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebang <sebang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:52:25 by haejokim          #+#    #+#             */
/*   Updated: 2023/01/15 17:09:48 by sebang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
#include "ex12/ft_print_memory.c"

int	main(void)
{
	//ex00
	char dest[6];
	char src[6] = "Hello";
	printf("< ex00 >\n");
	printf("-----------answer------------\n");
	strcpy(dest, src);
	printf("%s\n", dest);
	printf("-------------------------------\n");
	char d[6];
	ft_strcpy(d, src);
	printf("%s\n", d);
	printf("-----------output------------\n\n");
	
	//ex01
	char d1[10] = "abcabcabc";
	char d2[10] = "abcabcabc";
	char d3[10] = "abcabcabc";
	char d4[10] = "abcabcabc";
	printf("< ex01 >\n");
	printf("-----------answer------------\n");
	strncpy(d1, src, 3); //src보다 작은 사이즈가 주어질 때 널이 없음!
	printf("%s\n", d1);
	printf("%s\n", &d1[6]);
	strncpy(d2, src, 8);
	printf("%s\n", d2);
	printf("%s\n", &d2[8]); //null이 다 채워졌는지 체크
	printf("바로 위의 값은 무시. 문제 정의 상에서는 null로 채워져 프린트되지 않아야함\n");
	printf("-------------------------------\n");
	ft_strncpy(d3, src, 3);
	printf("%s\n", d3);
	printf("%s\n", &d3[6]);
	ft_strncpy(d4, src, 8);
	printf("%s\n", d4);
	printf("%s\n", &d4[8]);
	printf("-----------output------------\n\n");
	
	//ex02
	printf("< ex02 >\n");
	printf("-----------answer------------\n");
	printf("1 1 0\n");
	printf("-------------------------------\n");
	printf("%d %d %d\n", ft_str_is_alpha("afwrA"), ft_str_is_alpha(""), ft_str_is_alpha("asA \n"));
	printf("-----------output------------\n\n");
	
	//ex03
	printf("< ex03 >\n");
	printf("-----------answer------------\n");
	printf("1 1 0\n");
	printf("-------------------------------\n");
	printf("%d %d %d\n", ft_str_is_numeric(""), ft_str_is_numeric("123413499"), ft_str_is_numeric("124\n"));
	printf("-----------output------------\n\n");
	
	//ex04
	printf("< ex04 >\n");
	printf("-----------answer------------\n");
	printf("1 1 0\n");
	printf("-------------------------------\n");
	printf("%d %d %d\n", ft_str_is_lowercase("asdfj"), ft_str_is_lowercase(""), ft_str_is_lowercase("asdfAA13"));
	printf("-----------output------------\n\n");
	
	//ex05
	printf("< ex05 >\n");
	printf("-----------answer------------\n");
	printf("1 1 0\n");
	printf("-------------------------------\n");
	printf("%d %d %d\n", ft_str_is_uppercase("ASDFADFREGTHQFOZ"), ft_str_is_uppercase(""), ft_str_is_uppercase("ASFR13Das"));
	printf("-----------output------------\n\n");
	
	//ex06 확장 아스키코드 주의!!!!
	char	s1[2] = { 127 };
	char	s2[2] = { 0 };
	char	s3[3] = { 31 };
	char	s4[4] = { 32, 55, 95 };
	char	s5[2] = {200};
	printf("< ex06 >\n");
	printf("-----------answer------------\n");
	printf("0 1 0 1 0\n");
	printf("-------------------------------\n");
	printf("%d %d %d %d %d\n", ft_str_is_printable(s1), ft_str_is_printable(s2), ft_str_is_printable(s3), ft_str_is_printable(s4), ft_str_is_printable(s5));
	printf("-----------output------------\n\n");
	
	//ex07
	char	made[100] = "This is Made by <haejokim>";
	printf("< ex07 >\n");
	printf("-----------answer------------\n");
	printf("THIS IS MADE BY <HAEJOKIM>\n");
	printf("-------------------------------\n");
	printf("%s\n", ft_strupcase(made));
	printf("-----------output------------\n\n");
	
	//ex08
	printf("< ex08 >\n");
	printf("-----------answer------------\n");
	printf("this is made by haejokim\n");
	printf("-------------------------------\n");
	char	made1[100] = "This is Made by <haejokim>";
	printf("%s\n", ft_strlowcase(made1));
	printf("-----------output------------\n\n");
	
	//ex09
	printf("< ex09 >\n");
	printf("-----------answer------------\n");
	printf("Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un\n");
	printf("-------------------------------\n");
	char	ex09[100] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(ex09));
	printf("-----------output------------\n\n");
	
	//ex10
	char	d5[10] = "abcabcabc";
	char	d6[10] = "abcabcabc";
	char	d7[10] = "abcabcabc";
	char	d8[10] = "abcabcabc";
	printf("< ex10 >\n");
	printf("-----------answer------------\n");
	ft_strlcpy(d5, src, 3);
	printf("%s\n", d5);
	printf("%s\n", &d5[6]);
	ft_strlcpy(d6, src, 8);
	printf("%s\n", d6);
	printf("%s\n", &d6[6]);
	printf("-------------------------------\n");
	ft_strlcpy(d7, src, 3);
	printf("%s\n", d7);
	printf("%s\n", &d7[6]);
	ft_strlcpy(d8, src, 6);
	printf("%s\n", d8);
	printf("%s\n", &d8[6]);
	printf("-----------output------------\n\n");
	
	//ex11
	printf("< ex11 >\n");
	printf("-----------answer------------\n");
	printf("Coucou\\0atu vas bien ?\n");
	printf("\\c8\\7f\n");
	printf("-------------------------------\n");
	ft_putstr_non_printable("Concou\ntu vas bien ?");
	write(1, "\n", 1);
	char aa[3] = { 200, 127, 0};
	ft_putstr_non_printable(aa);
	printf("\n");
	printf("-----------output------------\n\n");
	
	//ex12
	printf("< ex12 >\n");
	char	c12[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	
	printf("----------answer----------\n");
	printf("%s\n", "00007ffee16ab3e0: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin\n00007ffee16ab3f0: 6368 6573 090a 0963 2020 6573 7420 666f ches...c  est fo\n00007ffee16ab400: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on \n00007ffee16ab410: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.\n00007ffee16ab420: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..\n00007ffee16ab430: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. ");
	printf("-------------------------\n");
	ft_print_memory((void *)c12, sizeof(c12));
	printf("----------output----------\n");
	return (0);
}