main:	main.o	funcoes.o
	gcc main.o funcoes.o -o main

main.o: main.c
	gcc -c main.c

funcoes.o:	funcoes.c	funcoes.h
	gcc -c funcoes.c

clean:
	rm *.o
