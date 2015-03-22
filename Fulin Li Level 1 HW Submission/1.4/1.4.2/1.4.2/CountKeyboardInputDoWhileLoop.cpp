// CountKeyboardInputDoWhileLoop.cpp
//
// Purpose: Caculate the amount of characters, the amount of words 
//			and the amount of newlines that have been typed, using a do while loop.
//
// @author Fulin Li
// @version 1.0 9/27/14

#include <stdio.h>

void main()
{
	int ASCII_input_character = NULL; // ASCII-value of the input
	int num_characters = 0; // number of characters input
	int num_words = 0; // number of words input
	int num_newlines = 0; // number of new lines input
	bool flg_last_character = false; // set to true when last input is a character, but false when not
	bool flg_last_new_line = false; // set to true when last input is a new line, but false when not

	printf("Please input text, using Ctrl+D to stop.\n");

	do
	{
		if (ASCII_input_character == 32) // If pressing space(ASCII-value = 32)
		{
			if (flg_last_character)
			{
				// If last input is a character, count as a new word.
				num_words++;
			}

			flg_last_character = false;
		}
		else if (ASCII_input_character == 10) // If starting a new line(ASCII-value = 10)
		{
			if (flg_last_character)
			{
				// If last input is a character, count as a new word.
				num_words++;
			}
			
			flg_last_character = false;
			flg_last_new_line = true;
		}
		else if (ASCII_input_character != NULL)
		{
			num_characters++;

			if (flg_last_new_line)
			{
				// If last input is a new line and current input is a character, count as a new line.
				num_newlines++;
			}

			flg_last_character = true;
		}
	} 
	while ((ASCII_input_character = getchar()) != 4);

	// At the end of the text, if last input is a character, the current word should be counted as a new word.
	if (flg_last_character)
	{
		num_words++;
	}

	if (num_words > 0)
	{
		num_newlines++;
	}

	printf("The amount of characters is %d.\nThe amount of words is %d.\nThe amount of new lines is %d.\n",
		num_characters, num_words, num_newlines);
}