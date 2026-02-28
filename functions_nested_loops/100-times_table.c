#include "main.h"

/**
	* print_number - prints a number with correct formatting
	* @n: number to print
	*/
void print_number(int n)
{
	if (n >= 100)
	{
	_putchar((n / 100) + '0');
	_putchar(((n / 10) % 10) + '0');
	}
	else
	{
	_putchar(' ');
	if (n >= 10)
	_putchar((n / 10) + '0');
	else
	_putchar(' ');
	}
	_putchar((n % 10) + '0');
}

/**
	* print_times_table - prints the n times table
	* @n: number of times table
	*/
void print_times_table(int n)
{
	int i, j;

	if (n < 0 || n > 15)
	return;

	for (i = 0; i <= n; i++)
	{
	for (j = 0; j <= n; j++)
	{
	if (j == 0)
	print_number(i * j);
	else
	{
	_putchar(',');
	print_number(i * j);
	}
	}
	_putchar('\n');
	}
}
