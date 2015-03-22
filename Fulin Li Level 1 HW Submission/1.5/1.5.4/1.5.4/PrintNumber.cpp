// PrintNumber.cpp
//
// Purpose: Use a recursive function printnumber() to print an integer digit by digit by using putchar().
//
// @author Fulin Li
// @version 1.0 9/27/14

#include <stdio.h>
#include <math.h>

void main()
{
	long long int i = NULL; // the integer input

	// Print the integer digit by digit
	// i - the integer input
	// No return value
	void printnumber(long long int i);

	// Ask the user to input an integer.
	printf("Please input an integer.\n");
	
	if (scanf_s("%lld", &i))
	{
		// If the user inputs an integer, call printnumber() to print the number digit by digit.
		printnumber(i);
	}
	else
	{
		// If the user fails to input an integer, send error message and exit.
		printf("Input Error.");
	}
}

void printnumber(long long int integer_number)
{
	// If the integer input is negative, print a "-".
	if (integer_number < 0)
	{
		// Get the absolute value of integer_number.
		integer_number = - integer_number;
		putchar('-');

		// After printing a digit, start a new line.
		putchar('\n');
	}

	long long int temp_integer_number = integer_number; // store the original value of integer_number
	long long int count_total_digit = 0; // the number of total digits
	long long int next_integer_number = 1; // the number returned aftering deleting the most significant digit from integer_number
	
	// Calculate the number of total digits.
	while (temp_integer_number / 10 != 0)
	{
		temp_integer_number /= 10;
		count_total_digit++;
	}
	
	// Print the most significant digit of integer_number.
	putchar(temp_integer_number + 48);
	// After printing a digit, start a new line.
	putchar('\n');

	if (count_total_digit == 0)
	{		
		// If integer_number only has one digit, stop printing.
		return;
	}
	else
	{
		// Get the number after changing all the digits of integer_number to 0
		// except the most significant digit of it
		for (long long int i = 0; i < count_total_digit; i++)
		{
			next_integer_number *= 10;
		}

		// Set the number left after deleting the most significant digit from integer_number to next_integer_number.
		next_integer_number = integer_number % next_integer_number;

		// Call the recursive function to print next_integer_number.
		printnumber(next_integer_number);
	}	
}