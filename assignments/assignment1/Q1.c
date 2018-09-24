/* CS261- Assignment 1 - Q.1*/
/* Name: Drake Seifert
 * Date: 10/7/15
 * Solution description: I allocated memory for an array of structs, created random numbers
 * using the rand() function and gave each student a random ID and test score. I then found
 * the min and max scores using if statements to compare the scores and found the average
 * by adding all the scores and dividing by the number of students. I then deallocated the 
 * array using the free() function.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student *stud = (struct student *)malloc(sizeof(struct student) * 10); 
     /*return the pointer*/
    return stud;
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
    int i, j, k;
    int x = 0;

    time_t t;
    srand((unsigned) time(&t));

    for(k = 0; k < 10 ; k++) {
        students[k].id = rand() % 10 + 1;
    }

    while(x < 10){
        int y = rand() % 10 + 1;

        for (i = 0; i < x; i++) {
            if(students[i].id == y){
                break;
            }
	}
            if(i == x){
                students[x++].id = y;
            }
    }
    for(j = 0; j < 10; j++) {
        students[j].score = rand() % 101;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
     int i;
     for(i = 0; i < 10; i++) {
          printf("%d %d\n", students[i].id, students[i].score);
     }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int i, min = 100, max = 0;
     float avg = 0;
     for(i = 0; i < 10; i++) {
          avg += students[i].score;
	  if(students[i].score < min) { //if students score is lower than current min,
	       min = students[i].score; //set min to current students score
	  }
	  if(students[i].score > max) {
	       max = students[i].score;
	  }
     }
     avg = avg / 10;
     
     printf("\nMin: %d\nMax: %d\nAverage: %.2f\n\n", min, max, avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if(stud != NULL)
          free(stud);
}

int main(){
    struct student* stud = NULL;
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
