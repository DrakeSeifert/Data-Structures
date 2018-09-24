/* CS261- Assignment 1 - Q.4*/
/* Name: Drake
 * Date: 10/7/15
 * Solution description: I used the methods from Q1 to create the array 
 * of structs and the methods from Q3 to sort the students' scores, making sure to also
 * change the array location of their ID if two positions got swapped.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     int i, j, k, dummy1, dummy2;
     for(i = 0; i < n; i++) {
         for(j = 0; j < n - 1; j++) {
             for(k = 0; k < n - j - 1; k++) {
                 if(students[k].score > students[k + 1].score) {
                     dummy1 = students[k].score;
                     dummy2 = students[k].id;
                     students[k].score = students[k + 1].score;
                     students[k].id = students[k + 1].id;
                     students[k + 1].score = dummy1;
                     students[k + 1].id = dummy2;
                 }
             }
         }
     }
     /* Remember, each student must be matched with their original score after sorting */
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10, i, j, x = 0;
    time_t t;
    srand((unsigned) time(&t));
    /*Allocate memory for n students using malloc.*/
    //struct student *stud = NULL;
    struct student *stud = (struct student *)malloc(sizeof(struct student) * n);
    /*Generate random IDs and scores for the n students, using rand().*/
    for(i = 0; i < n; i++) {
        stud[i].id = rand() % 10 + 1;
    }

    while(x < 10) {
        int y = rand() % 10 + 1;

	for (i = 0; i < x; i++) {
	    if(stud[i].id == y) {
	        break;
	    }
	}
	    if(i == x) {
	        stud[x++].id = y;
	    }
    }
    for(j = 0; j < 10; j++) {
	stud[j].score = rand() % 101;
    }
    /*Print the contents of the array of n students.*/
    for(i = 0; i < n; i++) {
        printf("%d %d\n", stud[i].id, stud[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(stud, n);
    /*Print the contents of the array of n students.*/
    printf("\nNew Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d %d\n", stud[i].id, stud[i].score);
    }
    
    return 0;
}
