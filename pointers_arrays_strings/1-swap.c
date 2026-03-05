#include "main.h"

/**
	* swap_int - swaps the values of two integers
	* @a: first integer pointer
	* @b: second integer pointer
	*/

void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
