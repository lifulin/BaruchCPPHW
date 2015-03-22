// TriangleSurfaceCalculator.cpp
//
// Purpose: Calculate the surface of a triangle with one 90 degree angle.
//
// @author Fulin Li
// @version 1.0 9/21/14

#include <stdio.h>

void main()
{
	double base = NULL ; // base of the triangle
	double height = NULL; // height of the triangle
	double triangle_surface = NULL; // surface of the triangle

	// Ask the user to input base and height of the triangle.
	printf("Please input the base and height of the triangle.\n");
	
	if (scanf_s("%lf %lf", &base, &height))
	{
		if (base > 0 && height > 0)
		{
			// If base and height are both positive numbers, then calculate surface of the triangle.
			triangle_surface = base * height / 2;
			// Print surface of the triangle on screen.
			printf("The surface of a right triangle with base %lf and height %lf is %lf.\n", base, height, triangle_surface);
		}
		else
		{
			// If either base or height is not positive number, send error message and exit.
			printf("Input Error.\n");
			return;
		}
	}
	else
	{
		// If either base or height is not positive number, send error message and exit.
		printf("Input Error.\n");
		return;
	}

	fflush(stdin);
}