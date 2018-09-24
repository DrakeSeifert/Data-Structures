#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	/* Test your linked list in here! */
	struct linkedList *lst = createLinkedList();
	TYPE a;

	if (isEmptyList(lst)) {
		printf("\nisEmptyList: Passed\n");
		printf("createLinkedList: Passed\n");
	}
	else
		printf("\nisEmptyList: Failed\n");
	
	addFrontList(lst, 5); // {5}
	addFrontList(lst, 10); // {10, 5}
	printf("list should have elements 10 and 5: ");
	_printList(lst);
	printf("addFrontList: Passed\n");

	addBackList(lst, 42); // {10, 5, 42}
	printf("Added 42 to end: ");
	_printList(lst);
	printf("addBackList: Passed\n");
	
	a = frontList(lst);
	printf("first element is %d\n", a);
	printf("frontList: Passed\n");
	a = backList(lst);
	printf("last element is %d\n", a);
	printf("backList: Passed\n");

	removeFrontList(lst); // {5, 42}
	printf("removed front: ");
	_printList(lst);
	printf("removeFrontList: Passed\n");

	removeBackList(lst); // {5}
	printf("removed back: ");
	_printList(lst);
	printf("removeBackList: Passed\n");
	printf("printList: Passed\n");

	addList(lst, 20); // {20, 5}
	addList(lst, 30); // {30, 20, 5}
	printf("list should have elements 30, 20, 5: ");
	_printList(lst);
	printf("addList: Passed\n");

	printf("Bag contains 20: ");
	if (containsList(lst, 20))
		printf("containsList: Passed\n");
	else
		printf("containsList: Failed\n");

	removeList(lst, 5); // {30, 20}
	printf("Removed 5, should be 30, 20: ");
	_printList(lst);

	printf("Bag DOES NOT contain 5: ");
	if (containsList(lst, 5))
		printf("removeList: Failed\n");
	else
		printf("removeList: Passed\n");

	return 0;
}


