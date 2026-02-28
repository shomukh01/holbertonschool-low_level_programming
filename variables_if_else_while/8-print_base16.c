#include <stdio.h>

/**
	* main - prints all numbers of base 16 in lowercase
	*
	* Return: Always 0 (Success)
	*/
int main(void)
{
	int n;

	for (n = 0; n < 10; n++)
	{
	putchar(n + '0');
	}

	for (n = 0; n < 6; n++)
	{
	putchar(n + 'a');
	}

	putchar('\n');

	return (0);
}
