default: prog

cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c	

testCirListDeque.o: cirListDeque.h testCirListDeque.c
	gcc -Wall -g -std=c99 -c testCirListDeque.c

prog: cirListDeque.o testCirListDeque.o
	gcc -Wall -g -std=c99 -o prog cirListDeque.o testCirListDeque.o

list: linkedList.h linkedList.c testLinkedList.c
	gcc -Wall -g -std=c99 linkedList.c testLinkedList.c -o testLinkedList

deque: cirListDeque.h cirListDeque.c testCirListDeque.c
	gcc -Wall -g -std=c99 cirListDeque.c testCirListDeque.c -o testCirListDeque
		
clean:
	rm cirListDeque.o
	rm testCirListDeque.o
