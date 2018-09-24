#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
	q->sentinel = malloc(sizeof(struct DLink));
	assert(q->sentinel != 0);
	q->sentinel->next = q->sentinel;
	q->sentinel->prev = q->sentinel;
	q->size = 0;
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	struct DLink *newLink = malloc(sizeof(struct DLink));
	newLink->value = val;
	return(newLink);
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	int i;
	assert(q != NULL);
	assert(lnk != NULL);
	assert(q->size != 0);
	struct DLink *current = q->sentinel->next;
	for(i = 0; i < q->size; i++) {
		if(current->value == lnk->value) {
			struct DLink *newLink = _createLink(v);
			newLink->next = lnk->next;
			newLink->prev = lnk;

			lnk->prev->next = newLink;
			lnk->prev = newLink;
			q->size++;
			
			return;
		}
		current = current->next;
	}
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	struct DLink *newLink = _createLink(val);
	newLink->next = q->sentinel;
	newLink->prev = q->sentinel->prev;

	q->sentinel->prev->next = newLink;
	q->sentinel->prev = newLink;

	q->size++;
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	struct DLink *newLink = _createLink(val);
	newLink->prev = q->sentinel;
	newLink->next = q->sentinel->next;

	q->sentinel->next->prev = newLink;
	q->sentinel->next = newLink;

	q->size++;
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	if(!isEmptyCirListDeque(q))
		return q->sentinel->next->value;
	else {
		printf("frontCirListDeque Fail: No items in list\n");
		exit(EXIT_FAILURE);
	}
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	if(!isEmptyCirListDeque(q))
		return q->sentinel->prev->value;
	else {
		printf("backCirListDeque Fail: No items in list\n");
		exit(EXIT_FAILURE);
	}
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	assert(q != NULL);
	assert(q->size != 0);
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	free(lnk);
	q->size--;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	assert(!isEmptyCirListDeque(q));
	q->sentinel->next->value = 0;
	q->sentinel->next->next->prev = q->sentinel;
	q->sentinel->next = q->sentinel->next->next;
	q->size--;
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	assert(!isEmptyCirListDeque(q));
	q->sentinel->prev->value = 0;
	q->sentinel->prev->prev->next = q->sentinel;
	q->sentinel->prev = q->sentinel->prev->prev;
	q->size--;
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	while(!isEmptyCirListDeque(q)) {
		_removeLink(q, q->sentinel->next);
	}
	free(q->sentinel);
}

/* 	Deallocate all the links and the deque itself. 

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteCirListDeque(struct cirListDeque *q) {
	assert(q != 0);
	freeCirListDeque(q);
	free(q);
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
	if (EQ(q->sentinel->next, q->sentinel))
		return 1;
	else
		return 0;
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	int i;
	assert(q != NULL);
	assert(q->size != 0);
	struct DLink *current = q->sentinel->next;
	for(i = 0; i < q->size; i++) {
		printf("%f ", current->value);
		current = current->next;
	}
	printf("\n");
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	assert(q != NULL);
	assert(q->size != 0);
	struct DLink *current = q->sentinel->next;
	struct DLink *temp = NULL;
	current = q->sentinel->next;
	while(current != q->sentinel) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	q->sentinel->next = temp->prev;
}
