#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"

int	main (void)
{
	printf("\n----ex04----\n");
	ft_putnbr_base(-0, "01");
	printf("\nnbr : 0, base : poneyvif\n");
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	printf("\nnbr : -2147483648, base : 0123456789abcdef\n");
	ft_putnbr_base(-342373, "jungyeki");
	printf("\nnbr : -342373, base : jungyeki\n");

	printf("\n----ex05----\n");

	printf("%d", ft_atoi_base("offffffffff", "poneyvif"));
	printf("\nstr : offffffffff, base : poneyvif\n");
	printf("%d", ft_atoi_base("","/G"));
	printf("\nstr : -80000000, base : 0123456789abcdef\n");
	printf("%d", ft_atoi_base("    ----++---+jungyeye0224", "jungyeki"));
	printf("\nstr :     ----++---+jungyeye0224, base : jungyeki\n");
	char *s = "    --+---+001520";
	printf("%d\n", ft_atoi_base(s,"0123456789"));
	printf("%d\n", ft_atoi_base("-FE","0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("---+-120t00","0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("FFFFFFFF","01234567089ABCDEF"));

}
