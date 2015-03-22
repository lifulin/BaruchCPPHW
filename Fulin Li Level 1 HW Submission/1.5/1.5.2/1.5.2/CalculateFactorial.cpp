// CalculateFactorial.cpp
//
// Purpose: Print the factorials of a non-negative integer, using recursive function.
//
// @author Fulin Li
// @version 1.0 9/27/14

#include <stdio.h>

void main()
{
	long long int integer_number = NULL; // the non-negative integer input

	// Calculate the factorials of a non-negative integer
	// integer_number - the non-negative integer input
	// Return the factorials of the integer.
	long long int factorial(long long int integer_number);

	// Ask the user to input a non-negative integer.
	printf("Please input a natural number.\n");

	if (scanf_s("%lld", &integer_number) >= 0)
	{
		// If the user inputs a non-negative integer, call the recursive function factorial().
		printf("The factorials of %lld is %lld.", integer_number, factorial(integer_number));
	}
	else
	{
		// If the user fails to input a non-negative integer, send error message and exit.
		printf("Input Error.");
	}
}

long long int factorial(long long int integer_number)
{
	if (integer_number == 0)
	{
		// 0! = 1.
		return 1;
	}
	else
	{
		// Call the recursive function
		// factorial(integer_number) = integer_number * factorial(integer_number - 1)
		return integer_number * factorial(integer_number - 1);
	}
}