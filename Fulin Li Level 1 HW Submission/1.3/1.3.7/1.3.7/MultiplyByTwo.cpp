// MultiplyByTwo.cpp
//
// Purpose: Efficiently multiply a number by a factor 2 to the power n, using left shift operator.
//
// @author Fulin Li
// @version 1.0 9/21/14

#include <stdio.h>

void main()
{
	long long int num_input; // number input
	long long int num_power; // power input

	// Ask the user to input the number to be multiplied.
	printf("Please input the integer to multiply.\n");
	
	if (!scanf_s("%lld", &num_input))
	{
		// If the number input is not an integer, send error message and exit.
		printf("Input Error: The number is not integer.\n");
		return;
	}

	// Ask the user to input the power.
	printf("Please input the power n.\n");
	fflush(stdin);

	if (!scanf_s("%lld", &num_power))
	{
		// If the power input is not an integer, send error message and exit.
		printf("Input Error: The number is not integer.\n");
		return;
	}

	// Print the result of multiplying num_input by a factor 2 to the power num_power on screen. 
	printf("Multiply %lld by a factor 2 to the power %lld, then we get %lld.\n", 
		num_input, num_power, (num_input << num_power));
	fflush(stdin);
}