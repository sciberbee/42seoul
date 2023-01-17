#include <stdio.h>
#include <string.h>

#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
// #include "ex04/ft_strstr.c"
// #include "ex05/ft_strlcat.c"

int	main(void)
{
	printf("\n----ex00----\n");
	char *s1 = "jungyeKi";
	char *s11 = "jungyeki";
	printf("%d   vs   %d : ft_strcmp   vs   strcmp\n", ft_strcmp("", s11), strcmp("", s11));
	printf("%d   vs   %d : ft_strcmp   vs   strcmp\n", ft_strcmp(s1, s11), strcmp(s1, s11));
	printf("두 값이 같아야 정답\n");

	printf("\n----ex01----\n");
	char *s2 = "jungyeKi";
	char *s22 = "juNgyeki";
	printf(" %d   vs   %d  : ft_strncmp   vs   strncmp : n = 0\n", ft_strncmp(s2, s22, 0), strncmp(s2, s22, 0));
	printf(" %d   vs   %d  : ft_strncmp   vs   strncmp : n = 2\n", ft_strncmp(s2, s22, 2), strncmp(s2, s22, 2));
	printf("%d   vs   %d : ft_strncmp   vs   strncmp : n = 9\n", ft_strncmp(s2, s22, 9), strncmp(s2, s22, 9));
	printf("각 쌍의 값이 모두 같아야 정답\n");

	printf("\n----ex02----\n");
	char d31[19] = "Jungyeki ";
	char *s31 = "is babo !";
	char d32[19] = "Jungyeki ";
	char *s32 = "is babo !";
	printf("    dest : Jungyeki   ,   src : is babo !\n");
	printf("%s   vs   %s : ft_strcat   vs   strcat\n", ft_strcat(d31, s31), strcat(d32, s32));
	printf("두 문자열이 같아야 정답\n");

	printf("\n----ex03----\n");
	char d41[17] = "Zip ";
	char *s41 = "Ga Go Sip Da";
	char d42[17] = "Zip ";
	char *s42 = "Ga Go Sip Da";
	char d43[17] = "Zip ";
	char *s43 = "Ga Go Sip Da";
	char d44[17] = "Zip ";
	char *s44 = "Ga Go Sip Da";
	printf("    dest : Zip   ,   src : Ga Go Sip Da\n");
	printf("%svs%s: ft_strncat   vs   strncat :  n = 3\n", ft_strncat(d41, s41, 3), strncat(d42, s42, 3));
	printf("%svs%s: ft_strcat   vs   strncat : n = 13\n", ft_strncat(d43, s43, 13), strncat(d44, s44, 13));
	printf("각 쌍의 값이 모두 같아야 정답\n");
	/*
	printf("\n----ex04----\n");
	char *d51 = "jungyekim want to go home";
	char *d52 = "jungyekim want to go home";
	char *s55 = "go";
	char *s555 = "";
	printf("    haystack : jungyeki want to go home   ,   needle : go   ,   empty needle\n");
	printf("%s   vs   %s   :   ft_strstr   vs   strstr\n", ft_strstr(d51, s55), strstr(d52, s55));
	printf("%s   vs   %s   :   ft_strstr   vs   strstr\n", ft_strstr(d51, s555), strstr(d52, s555));
	printf("각 문자열이 같아야 정답\n");
	
	printf("\n----ex05----\n");
	char d61[30] = "this test is";
	char d62[30] = "this test is";
	char d63[30] = "this test is";
	char d64[30] = "this test is";
	char *s61 = "made by jungyeki.";
	char *s62 = "made by jungyeki.";
	char *s63 = "made by jungyeki.";
	char *s64 = "made by jungyeki.";
	printf("%u   vs   %lu : 17 , ft_strlcat : size = 0\n", ft_strlcat(d61, s61, 0), strlcat(d62, s62, 0));
	printf("%u   vs   %lu : 29 , ft_strlcat : size = 29\n", ft_strlcat(d63, s63, 29), strlcat(d64, s64, 29));
	printf("각 두 쌍의 숫자들이 같으면 정답.\n");

	printf("\nsoohkang, wocheon 님 께서 C03 TC 작성에 도움을 주셨습니다.\n");
	printf("\nC03 푸시느라 고생하셨습니다.\n\n");*/
	return (0);
}
