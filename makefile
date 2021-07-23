main:	main.o	matrix.o	menu.o
	gcc main.o matrix.o menu.o -o main

main.o: main.c
	gcc -c main.c

matrix.o: matrix.c matrix.h
	gcc -c matrix.c

menu.o: menu.c menu.h
	gcc -c menu.c

clean:
	rm *.o main