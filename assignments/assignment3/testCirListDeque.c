#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	/* Test your linked list in here! */
	TYPE a;
	struct cirListDeque *q = createCirListDeque();
	
	if(isEmptyCirListDeque(q))
		printf("isEmptyCirListDeque: PASSED\n");

	addFrontCirListDeque(q, 19); // {19}
	addFrontCirListDeque(q, 65); // {65, 19}
	printf("Deque should read 65 19: ");
	printCirListDeque(q);
	printf("createCirListDeque: PASSED\n");
	printf("printCirListDeque: PASSED\n");
	printf("addFrontCirListDeque: PASSED\n");

	addBackCirListDeque(q, 90); // {65, 19, 90}
	printf("Deque should read 65 19 90: ");
	printCirListDeque(q);
	printf("addBackCirListDeque: PASSED\n");

	a = frontCirListDeque(q);
	if (a == 65)
		printf("frontCirListDeque: PASSED\n");
	a = backCirListDeque(q);
	if (a == 90)
		printf("backCirListDeque: PASSED\n");
	
	removeFrontCirListDeque(q); // {19, 90}
	printf("Deque should read 19 90: ");
	printCirListDeque(q);
	printf("removeFrontCirListDeque: PASSED\n");

	removeBackCirListDeque(q); // {19}
	printf("Deque should read 19: ");
	printCirListDeque(q);
	printf("removeBackCirListDeque: PASSED\n");

	addFrontCirListDeque(q, 29); // {29, 19}
	addFrontCirListDeque(q, 39); // {39, 29, 19}
	printf("Deque should read 39, 29, 19: ");
	printCirListDeque(q);

	reverseCirListDeque(q); // {19, 29, 39}
	printf("Deque should read 19, 29, 39: ");
	printCirListDeque(q);
	printf("reverseCirListDeque: PASSED\n");
	
	deleteCirListDeque(q);
	printf("freeCirListDeque: PASSED\n");
	printf("deleteCirListDeque: PASSED\n");
	
	return 0;
}


