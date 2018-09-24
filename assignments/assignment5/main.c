#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
  char taskDescription[TASK_DESC_SIZE];
  FILE *myfile = 0;
  int priority;
  TaskP newTask;

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
	
	if(cmd == 'l') {
		char filename[32];
		printf("Enter filename: ");
		scanf("%s", filename);
		if(access(filename, F_OK) != -1) {
			myfile = fopen(filename, "r");
			loadList(mainList, myfile);
			fclose(myfile);
			printf("\nList loaded!!!!!!!!!!\n\n");
		}
		else
			printf("\nFile does not exist\n");
        	while (getchar() != '\n');
	}
	else if(cmd == 's') {
		char filename[32];
		printf("enter filename: ");
		scanf("%s", filename);
		myfile = fopen(filename, "w");
		saveList(mainList, myfile);
		printf("\nList saved!!!!!!!!!!!!!\n\n");
		fclose(myfile);
        	while (getchar() != '\n');
	}
	else if(cmd == 'a') {
		printf("Please enter the task description: ");
		scanf("%[^\n]s", taskDescription);
		printf("Please enter the task priority: ");
		scanf("%d", &priority);
		newTask = createTask(priority, taskDescription);
		addHeap(mainList, newTask, compare);
		printf("\nTask added!!!!!!\n\n");
        	while (getchar() != '\n');
	}
	else if(cmd == 'g') {
		if(sizeDynArr(mainList) == 0) {
			printf("Your to-do list is empty!\n");
		}
		else {	
			newTask = getMinHeap(mainList);
			printf("First task: %s  Priority: %d\n", 
				newTask->description, newTask->priority);
		}
	}
	else if(cmd == 'r') {
		removeMinHeap(mainList, compare);
		printf("\nFirst task removed!!!!!\n\n");
	}
	else if(cmd == 'p') {
		if(sizeDynArr(mainList) == 0) {
			printf("Your to-do list is empty!\n");
		}
		else printList(mainList);
	}
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
