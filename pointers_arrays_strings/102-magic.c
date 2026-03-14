#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	p = a;

	*(p + 5) = 98;

	for (n = 0; n < 5; n++)
	{
		printf("a[%d] = %d\n", n, a[n]);
	}
	return (0);
}
