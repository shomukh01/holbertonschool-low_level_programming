#include "main.h"
#include <stdlib.h>

/**
	* malloc_checked - allocates memory
	* @b: number of bytes
	*
	* Return: pointer
	*/
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (!p)
		exit(98);
	return (p);
}
