// Multiply.h
//
// Purpose: Define macros to get the maximum of two or three numbers.
//
// @author Fulin Li
// @version 1.0 11/01/14

#ifndef MAX2
#define MAX2(x, y) ((x > y) ? x : y)
#endif

#ifndef MAX3
#define MAX3(x, y, z) (MAX2(MAX2(x, y), z))
#endif
