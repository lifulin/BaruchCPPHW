// NumberShift.cpp
//
// Purpose: Shift an integer two places to the right.
//
// @author Fulin Li
// @version 1.0 9/21/14

#include <stdio.h>

void main()
{
	long long int i; // integer input
	long long int i_right_shift_2; // result of shifting i two places to the right
	
	// Ask the user to input an integer.
	printf("Please input an integer.\n");

	if (scanf_s("%lld", &i))
	{
		// Get the result after shifting.
		i_right_shift_2 = i >> 2;

		// Print the result after shifting on screen.
		printf("Shift %lld two places to the right, then we get %lld.\n", i, i_right_shift_2);

		// i is a signed integer, so an arithmetic shift is performed.
		printf("An arithmetic shift if performed.\n");
	}
	else
	{
		// If the input is not an integer, send error message and exit.
		printf("Input Error: Input is not an integer.\n");
		return;
	}	
	
	fflush(stdin);
}