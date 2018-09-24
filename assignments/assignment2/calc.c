#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "dynamicArray.h"

#define PI 3.14159
#define E  2.71828

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	double ans;
	int a, b;
	if(!(sizeDynArr(stack) >= 2)) { //checks that there are two numbers to add
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 2; //element right below top of stack
	b = sizeDynArr(stack) - 1; //element at top of stack
	ans = (getDynArr(stack, a) + getDynArr(stack, b)); //adds the two numbers
	putDynArr(stack, a, ans); //replaces element right below stack with new num
	popDynArr(stack); //removes top element and decrements size by one
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	double ans;
	int a, b;
	if(!(sizeDynArr(stack) >= 2)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 2;
	b = sizeDynArr(stack) - 1;
	ans = (getDynArr(stack, a) - getDynArr(stack, b));	
	putDynArr(stack, a, ans);
	popDynArr(stack); 
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double ans;
	int a, b;
	if(!(sizeDynArr(stack) >= 2)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 2;
	b = sizeDynArr(stack) - 1;
	ans = (getDynArr(stack, a) / getDynArr(stack, b));	
	putDynArr(stack, a, ans);
	popDynArr(stack); 
}

void multiply(struct DynArr *stack)
{
	double ans;
	int a, b;
	if(!(sizeDynArr(stack) >= 2)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 2;
	b = sizeDynArr(stack) - 1;
	ans = (getDynArr(stack, a) * getDynArr(stack, b));	
	putDynArr(stack, a, ans);
	popDynArr(stack); 
}

void power(struct DynArr *stack)
{
	double ans;
	int a, b;
	if(!(sizeDynArr(stack) >= 2)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 2;
	b = sizeDynArr(stack) - 1;
	ans = pow(getDynArr(stack, a), getDynArr(stack, b));	
	putDynArr(stack, a, ans);
	popDynArr(stack); 
}

void square(struct DynArr *stack)
{
	double ans;
	int a;
	if(!(sizeDynArr(stack) >= 1)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 1;
	ans = pow(getDynArr(stack, a), 2);	
	putDynArr(stack, a, ans);
}

void cube(struct DynArr *stack)
{
	double ans;
	int a;
	if(!(sizeDynArr(stack) >= 1)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 1;
	ans = pow(getDynArr(stack, a), 3);	
	putDynArr(stack, a, ans);
}

void absoluteValue(struct DynArr *stack)
{
	double ans;
	int a;
	if(!(sizeDynArr(stack) >= 1)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 1;
	ans = getDynArr(stack, a);
	if (ans < 0)
		ans = (getDynArr(stack, a) * -1);
	putDynArr(stack, a, ans);
}

void squareRoot(struct DynArr *stack)
{
	double ans;
	int a;
	if(!(sizeDynArr(stack) >= 1)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 1;
	ans = pow(getDynArr(stack, a), 0.5);	
	putDynArr(stack, a, ans);
}

void exponential(struct DynArr *stack)
{
	double ans;
	int a;
	if(!(sizeDynArr(stack) >= 1)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 1;
	ans = pow(E, getDynArr(stack, a));	
	putDynArr(stack, a, ans);
}

void naturalLog(struct DynArr *stack)
{
	double ans;
	int a;
	if(!(sizeDynArr(stack) >= 1)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 1;
	ans = log(getDynArr(stack, a));	
	putDynArr(stack, a, ans);
}

void loga(struct DynArr *stack)
{
	double ans;
	int a;
	if(!(sizeDynArr(stack) >= 1)) {
		printf("Error: Too few inputs\n");
		exit(EXIT_FAILURE);
	}
	a = sizeDynArr(stack) - 1;
	ans = log10(getDynArr(stack, a));	
	putDynArr(stack, a, ans);
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	double num;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i = 1; i < numInputTokens; i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);
		else if(strcmp(s, "^3") == 0)
			cube(stack);
		else if(strcmp(s, "abs") == 0)
			absoluteValue(stack);
		else if(strcmp(s, "sqrt") == 0)
			squareRoot(stack);
		else if(strcmp(s, "exp") == 0)
			exponential(stack);
		else if(strcmp(s, "ln") == 0)
			naturalLog(stack);
		else if(strcmp(s, "log") == 0)
			loga(stack);
		else 
		{
			if (isNumber(s, &num) || !strcmp(s, "pi") || !strcmp(s, "e")) {
				if (!strcmp(s, "pi"))
					num = PI;
				else if (!strcmp(s, "e"))
					num = E;
				pushDynArr(stack, num);
			}
			else {
				printf("Error: Unrecognized Input\n");
				exit(EXIT_FAILURE);
			}	
		}
	}	//end for 

	if (sizeDynArr(stack) == 1) {
		result = topDynArr(stack);
		popDynArr(stack);
		return result;
	}
	else {
		printf("Error: Invalid Input\n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	double ans;

	if (argc == 1)
		return 0;

	ans = calculate(argc,argv);
	printf("%f\n", ans);
	return 0;
}
