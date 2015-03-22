// CountKeyboardInputSwitchCase.cpp
//
// Purpose: Caculate the amount of characters, the amount of words 
//			and the amount of newlines that have been typed, using a while loop and switch-case statement.
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

	printf("Please input text, using ctrl+D to stop.\n");

	while ((ASCII_input_character = getchar()) != 4)
	{
		switch (ASCII_input_character)
		{
			// If pressing space(ASCII-value = 32)
			case 32: 
				switch (flg_last_character)
				{
					// If last input is a character, count as a new word.
					case 1:					
						num_words++;
						break;
					default:
						break;
				}

				flg_last_character = false;
				break;

			// If starting a new line(ASCII-value = 10)
			case 10:
				switch (flg_last_character)
				{
					// If last input is a character, count as a new word.
					case 1:
						num_words++;
						break;
					default:
						break;
				}

				flg_last_character = false;
				flg_last_new_line = true;
				break;
			default:
				num_characters++;

				switch (flg_last_new_line)
				{
					// If last input is a new line and current input is a character, count as a new line.
					case 1:
						num_newlines++;
					default:
						break;
				}

				flg_last_character = true;
				break;
		}
	}

	// At the end of the text, if last input is a character, the current word should be counted as a new word.
	switch (flg_last_character)
	{
		case 1:
			num_words++;
			break;
		default:
			break;
	}

	switch (num_words)
	{
		case 0:
			break;
		default:
			num_newlines++;
			break;
	}
	
	printf("The amount of characters is %d.\nThe amount of words is %d.\nThe amount of new lines is %d.\n",
		num_characters, num_words, num_newlines);
}