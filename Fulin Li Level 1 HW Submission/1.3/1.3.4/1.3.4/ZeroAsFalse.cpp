// ZeroAsFalse.cpp
//
// Purpose: Printing if someone is married or not,
//			to test that 0 (zero) is interpreted as FALSE and non-zero is interpreted as TRUE.	
//
// @author Fulin Li
// @version 1.0 9/21/14

#include <stdio.h>

void main()
{
	int married = NULL; // indicate marital status, 0 means FALSE
	
	// Ask the user to input 0 or 1 to indicate one's marital status.
	printf("Please input 1 if you're married, or 0 if you're not married.\n");

	if (scanf_s("%d", &married))
	{
		if (!married || married == 1) // If the user input 0 or 1
		{
			// Using ?: operator and a single printf() to print the marital status on screen.
			// married = 0 is intepreted as FALSE.
			// married = 1 is intepreted as TRUE.
			printf(married ? "You are married.\n" : "You are not married.\n");
		}
		else
		{
			// If the user inputs a number that is not 0 or 1, send error message and exit.
			printf("Input Error: The input integer does not equal to 0 or 1.\n");
			return;
		}		
	}
	else
	{
		// If the user does not input a number, send error message and exit
		printf("Input Error: The character you input is not integer.\n");
		return;
	}

	fflush(stdin);
}