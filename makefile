main:	main.o	matrix.o
	gcc main.o matrix.o -o main

main.o: main.c
	gcc -c main.c

funcoes.o:	matrix.c matrix.h
	gcc -c funcoes.c

clean:
	rm *.o
