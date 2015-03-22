/* Operators */

#include <stdio.h>

int main()
{
	int x;

	x = -3 + 4 * 5 - 6;
	printf("x=%d\n", x); // x=11

	x = 3 + 4 % 5 - 6;
	printf("x=%d\n", x); // x=1

	x = -3 * 4 % -6 / 5;
	printf("x=%d\n", x); // x=0

	x = (7 + 6) % 5 / 2;
	printf("x=%d\n", x); // x=1

	return 0;
}