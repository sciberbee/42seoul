for file in ./*.c
do
	gcc -c $file
done
ar rcus libft.a *.o