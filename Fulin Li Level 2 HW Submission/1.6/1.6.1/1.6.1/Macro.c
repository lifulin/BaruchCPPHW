// Macro.c
//
// Purpose: Print two variables using macros.
//
// @author Fulin Li
// @version 1.0 11/01/14

#include <stdio.h>
#include "Defs.h"

void main()
{
	double a, b;

	// Ask the user to input a and b.
	printf("Please input two numbers using the following format:\na b\n");

	if (scanf_s("%lf %lf", &a, &b))
	{
		// Print variable a.
		PRINT1(a, b);

		// Print variable a and b.
		PRINT2(a, b);
	}
	else
	{
		printf("Input Error.\n");
	}	
}