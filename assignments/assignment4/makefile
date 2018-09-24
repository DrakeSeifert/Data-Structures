all: prog1 prog2

prog1: bst.o compare1.o
	gcc -g -Wall -std=c99 -o prog1 bst.o compare1.o

compare1.o: compare1.c
	gcc -g -Wall -std=c99 -c compare1.c
		
prog2: bst.o compare2.o
	gcc -g -Wall -std=c99 -o prog2 bst.o compare2.o

compare2.o: compare2.c
	gcc -g -Wall -std=c99 -c compare2.c
		
bst.o: bst.c bst.h
	gcc -g -Wall -std=c99 -c bst.c

clean:	
	rm bst.o
	rm compare1.o
	rm compare2.o
	rm prog1
	rm prog2
