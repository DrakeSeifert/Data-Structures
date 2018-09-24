/* CS261- Assignment 1 - Q.2*/
/* Name: Drake
 * Date: 10/7/15
 * Solution description: To pass by reference I had to create pointer variables in main()
 * that pointed to the address of the variables I intended to manipulate: x and y. I 
 * could then pass these pointers into foo which would overwrite the initial declarations
 * I had made in main. Z was passed by value and therefore remain unchanged.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    (*a) += (*a);
    /*Set b to half its original value*/
    (*b) /= 2;
    /*Assign a+b to c*/
    c = (*a) + (*b);
    /*Return c*/
    return c;
}

int main(){
    int a;
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x = 7, y = 8, z = 9; 
    int *px = &x, *py = &y;
    /*Print the values of x, y and z*/
    printf("x = %d\ny = %d\nz = %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    a = foo(px, py, z);
    /*Print the value returned by foo*/
    printf("foo returned %d\n", a);
    /*Print the values of x, y and z again*/
    printf("x = %d\ny = %d\nz = %d\n", x, y, z);
    /*Is the return value different than the value of z?  Why?*/
    /*Yes because z's value was manipulated in foo(), and foo() returned
     * this new number. z's value in main() however remains unchanged.*/
    return 0;
}
    
    
