main: main.o fonction.o  affichage.o
	gcc -o main main.o fonction.o affichage.o -lm

main.o: main.c main.h
	gcc -c -Wall -g main.c -lm

fonction.o: fonction.c
	gcc -c -Wall -g fonction.c -lm

affichage.o: affichage.c
	gcc -c -Wall -g affichage.c -lm