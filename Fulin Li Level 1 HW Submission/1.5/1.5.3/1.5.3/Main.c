// Main.c
//
// Purpose: Give the variable i a value and call the function print() in Print.c.
//
// @author Fulin Li
// @version 1.0 9/27/14

#include <stdio.h>
#include "Multiply.h"

void main()
{
	double i;

	// Ask the user tp input a number.
	printf("Please input a number.\n");

	if (scanf_s("%lf", &i))
	{
		// If the user input a number, call print() to multiplies i by 2 and print it.
		print(i);
	}
	else
	{
		// If the user fails to input a number, send error message and exit.
		printf("Input Error.");
	}
}