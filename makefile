main:	main.o	matriz.o	menu.o
	gcc main.o matriz.o menu.o -o main

main.o: main.c
	gcc -c main.c

matriz.o: matriz.c matriz.h
	gcc -c matriz.c

menu.o: menu.c menu.h
	gcc -c menu.c

clean:
	rm *.o main