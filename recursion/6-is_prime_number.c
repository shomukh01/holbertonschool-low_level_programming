#include "main.h"

int helper(int n, int i);

/**
 * is_prime_number - checks if number is prime
 * @n: number
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (helper(n, 2));
}

/**
 * helper - checks divisibility
 * @n: number
 * @i: divisor
 * Return: 1 or 0
 */
int helper(int n, int i)
{
	if (i * i > n)
		return (1);

	if (n % i == 0)
		return (0);

	return (helper(n, i + 1));
}
