#include <stdio.h>

/**
 * main - finds and prints the largest prime factor
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long n;
	unsigned long i;

	n = 612852475143;

	while (n % 2 == 0)
		n = n / 2;

	for (i = 3; i * i <= n; i = i + 2)
	{
		while (n % i == 0)
			n = n / i;
	}

	printf("%lu\n", n);

	return (0);
}
