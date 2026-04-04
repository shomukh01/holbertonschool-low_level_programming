#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates array from min to max
 * @min: start value
 * @max: end value
 *
 * Return: pointer to array, or NULL
 */
int *array_range(int min, int max)
{
	int *p;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	p = malloc(sizeof(int) * size);
	if (!p)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = min + i;

	return (p);
}
