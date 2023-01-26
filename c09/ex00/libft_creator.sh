for file in ./*.c
do
	name=basename 
	gcc -Wall -Wextra -Werror -c file 
done


#gcc -Wall -Wextra -Werror -c *.o *.c
#ar rc libft.a *.o