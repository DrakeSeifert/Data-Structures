/* CS261- Assignment 1 - Q. 0*/
/* Name: Drake Seifert
 * Date: 10/7/15
 * Solution description: Addresses are printed using %p for the pointer variable and integer
 * values are printed with %d. The address of a variable is printed with &, the value pointed
 * to is *, and the value of a variable itself is just the variable name.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("value pointed to by iptr: %d\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("address pointed to by iptr: %p\n", iptr);
     /*Print the address of iptr itself*/
     printf("address of iptr: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 3;
    /*print the address of x*/
    printf("x's address: %p\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("The value of x: %d\n", x);
    return 0;
}
