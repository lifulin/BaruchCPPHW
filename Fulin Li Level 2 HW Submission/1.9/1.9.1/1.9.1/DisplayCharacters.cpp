// DisplayCharacters.cpp
//
// Purpose: Display characters line by line.
//
// @author Fulin Li
// @version 1.0 11/02/14

#include <stdio.h>

#ifndef MAX_LENGTH
#define MAX_LENGTH 10000
#endif

void main()
{ 
	int char_input; // a character input
	int n_count = 0; // number of characters in the current line
	char str[MAX_LENGTH]; // the string to store the characters of the current line
	
	// Print the contents of current line on screen
	// str - contents of the current line
	// n_count - number of characters in the current line.
	void PrintCharOnScreen(char str[MAX_LENGTH], int n_count);

	// Ask the user to input characters.
	printf("Please input characters, use ENTER to display characters line by line, use CTRL + A to end.\n");

	// When the user doesn't input CTRL + A, keep reading characters.
	while ((char_input = getchar()) != 1)
	{
		// When the user press ENTER, print the current line on screen.
		if (char_input == 10 && n_count > 0)
		{
			PrintCharOnScreen(str, n_count);

			// Intialize the number of characters belong to the next line to 0.
			n_count = 0;
			continue;
		}

		// Add the character to str.
		str[n_count] = char_input;
		n_count++;
	}

	// When the current line ends with CTRL + A and then ENTER
	if (n_count > 0)
	{
		// Print the current line on screen.
		PrintCharOnScreen(str, n_count);
	}

	// When program ends, display the following message.
	printf("CTRL + A is a correct ending.\n");
}

void PrintCharOnScreen(char str[MAX_LENGTH], int n_count)
{
	for (int i = 0; i <= n_count - 1; i++)
	{
		putchar(str[i]);
	}

	putchar('\n');
}