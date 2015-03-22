// Swap.cpp
//
// Purpose: Exchange the value of two variables.
//
// @author Fulin Li
// @version 1.0 11/02/14

#include <stdio.h>

void main()
{
	double i, j;

	// Swap two numbers
	// pi - pointer to the first number
	// pj - pointer to the second number
	void Swap(double* pi, double* pj);

	// Ask the user to input two numbers.
	printf("Please input two numbers in the following format:\ni j\n");

	if (scanf_s("%lf %lf", &i, &j))
	{
		printf("i = %lf, j = %lf.\n", i, j);

		// Swap i and j.
		Swap(&i, &j);

		printf("If we swap i and j, then i = %lf, j = %lf.\n", i, j);
	}
	else
	{
		printf("Input Error.\n");
	}
}

void Swap(double* pi, double* pj)
{
	double temp;
	
	temp = (*pi);
	(*pi) = (*pj);
	(*pj) = temp;	
}