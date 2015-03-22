// Minus.cpp
//
// Purpose: Call the function minus() to calculate the difference of two numbers.
//
// @author Fulin Li
// @version 1.0 9/27/14

#include <stdio.h>

void main()
{
	double number1 = NULL; // the first number input
	double number2 = NULL; // the second number input

	// Calculate the difference (regular subtraction) of two numbers
	// number1 - the first number
	// number2 - the second number
	// Return the difference of the two numbers.
	double minus(double number1, double number2);

	// Ask the user to input two numbers.
	printf("Please input two numbers in the following format: number1 number2\n");

	if (scanf_s("%lf %lf", &number1, &number2))
	{
		// If the user inputs two numbers, call minus() to get the difference of the two numbers.
		// Print the result on screen.
		printf("%lf minus %lf equals to %lf", number1, number2, minus(number1, number2));
	}
	else
	{
		// If the user fails to input two numbers, send error message and exit.
		printf("Input Error.");
	}
}

double minus(double number1, double number2)
{
	// Return the result of regular subtraction.
	return number1 - number2;
}