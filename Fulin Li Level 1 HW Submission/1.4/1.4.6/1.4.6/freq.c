// freq.c
//
// Purpose: Count how many times each of the numbers 0-4 have been typed, using a switch-case statement.
//
// @author Fulin Li
// @version 1.0 9/27/14

#include <stdio.h>

void main()
{
	char input_character = NULL; // input character
	int n_zero = 0; // times that 0 has been typed
	int n_one = 0; // times that 1 has been typed
	int n_two = 0; // times that 2 has been typed
	int n_three = 0; // times that 3 has been typed
	int n_four = 0; // times that 4 has been typed
	int n_others = 0; // times that other characters has been typed
	
	printf("%s", "Please input characters, you can halt the input with ^Z(EOF).\n");
	
	while ((input_character = getchar()) != EOF)
	{
		// Calculate the times that each number has been typed.
		switch (input_character)
		{
			case '0':
				n_zero++;
				break;
			case '1':
				n_one++;
				break;
			case '2':
				n_two++;
				break;
			case '3':
				n_three++;
				break;
			case '4':
				n_four++;
				break;
			default:
				n_others++;
				break;
		}
	}

	// Print the amount of times each of the numbers 0-4 has been typed.
	printf("0 has been typed %d times.\n", n_zero);
	printf("1 has been typed %d times.\n", n_one);
	printf("2 has been typed %d times.\n", n_two);
	printf("3 has been typed %d times.\n", n_three);
	printf("4 has been typed %d times.\n", n_four);
}