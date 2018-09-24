/* CS261- Assignment 1 - Q.3*/
/* Name: Drake Seifert
 * Date: 10/7/15
 * Solution description: Using malloc() I created an array of size n, and then proceeded
 * to fill the array using the rand() function. I then sorted the array using the 
 * bubble sort method.
 */
 
#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    int i, j, k, dummy;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - 1; j++) {
            for(k = 0; k < n - j - 1; k++) {
                if(number[k] > number[k + 1]) {
                    dummy = number[k];
                    number[k] = number[k + 1];
                    number[k + 1] = dummy;
                }
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20, i;
    int *pn = &n;
    /*Allocate memory for an array of n integers using malloc.*/
    pn = (int *)malloc(sizeof(int) * n);
    /*Fill this array with random numbers between 0 and n, using rand().*/
    for(i = 0; i < n; i++) {
        pn[i] = rand() % (n + 1);
    }
    /*Print the contents of the array.*/
    for(i = 0; i < n; i++) {
        printf("%d ", pn[i]);
    }
    /*Pass this array along with n to the sort() function.*/
    sort(pn, n);
    /*Print the contents of the array.*/  
    printf("\n\n");  
    for(i = 0; i < n; i++) {
        printf("%d ", pn[i]);
    }
    printf("\n\n");  
    
    return 0;
}
