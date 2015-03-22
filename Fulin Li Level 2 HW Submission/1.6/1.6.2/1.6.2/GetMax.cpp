// GetMax.cpp
//
// Purpose: Get the maximum value of two numbers using macro MAX2,
//			Get the maximum value of three numbers using macro MAX3.
//
// @author Fulin Li
// @version 1.0 11/01/14

#include <stdio.h>
#include "Defs.h"

void main()
{
	double a, b, c;

	// Ask the user to input three numbers.
	printf("Please input three numbers in the following format:\na b c\n");

	if (scanf_s("%lf %lf %lf", &a, &b, &c))
	{
		// Print the maximum value of a and b using MAX2.
		printf("The maximum value of %lf and %lf is %lf.\n", a, b, MAX2(a, b));

		// Print the maximum value of a, b and c using MAX3.
		printf("The maximum value of %lf, %lf and %lf is %lf.\n", a, b, c, MAX3(a, b, c));
	}
	else
	{
		printf("Input Error.\n");
	}
}