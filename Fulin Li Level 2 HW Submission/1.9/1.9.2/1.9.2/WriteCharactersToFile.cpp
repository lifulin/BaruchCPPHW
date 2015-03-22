// WriteCharactersToFile.cpp
//
// Purpose: Write characters to a file line by line.
//
// @author Fulin Li
// @version 1.0 11/02/14

#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_LENGTH
#define MAX_LENGTH 10000
#endif

#ifndef MAX_NAME_LENGTH
#define MAX_NAME_LENGTH 20
#endif

void main()
{
	int char_input; // a character input
	int n_count = 0; // number of characters in the current line
	char str[MAX_LENGTH]; // the string to store the characters of the current line
	char str_file[MAX_NAME_LENGTH]; // the string to store file name
	
	// Write the current line to file
	// str_file - file name
	// str - the contents of currentline
	// n_count - number of characters in the current line.
	void WriteToFile(char str_file[MAX_NAME_LENGTH], char str[MAX_LENGTH], int n_count);

	// Ask the user to input file name.
	printf("Please input a string as file name, example:\nfile.txt\n");

	// Get file name.
	gets_s(str_file);
	
	// Ask the user to input characters.
	printf("Please input characters, use ENTER to write characters to the specified file, use CTRL + A to end.\n");

	// When the user doesn't input CTRL + A, keep reading characters.
	while ((char_input = getchar()) != 1)
	{
		// When the user press ENTER
		if (char_input == 10 && n_count > 0)
		{
			// Write the current line to file.
			WriteToFile(str_file, str, n_count);
			
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
		// Write the current line to file.
		WriteToFile(str_file, str, n_count);
	}

	// When program ends, display the following message.
	printf("CTRL + A is a correct ending.\n");
}

void WriteToFile(char str_file[MAX_NAME_LENGTH], char str[MAX_LENGTH], int n_count)
{
	errno_t err; // indicate whether the file is opened
	FILE* fp; // file handle

	// Try to open the file with user specified name.
	err = fopen_s(&fp, str_file, "a+");

	// If failing to open the file, return.
	if (err != 0)
	{
		printf("Error: File not opened.");
		return;
	}

	// Write the current line to the file.
	for (int i = 0; i <= n_count - 1; i++)
	{
		fputc(str[i], fp);
	}

	fputc('\n', fp);

	// Close the file.
	fclose(fp);
}
