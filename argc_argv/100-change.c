#include <stdio.h>
#include <stdlib.h>

int count_coins(int cents);

/**
 * main - prints minimum number of coins for change
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	printf("%d\n", count_coins(cents));

	return (0);
}

/**
 * count_coins - calculates minimum coins
 * @cents: amount
 * Return: coins number
 */

int count_coins(int cents)
{
	int coins = 0;

	if (cents <= 0)
		return (0);

	while (cents >= 25)
	{
		cents -= 25;
		coins++;
	}
	while (cents >= 10)
	{
		cents -= 10;
		coins++;
	}
	while (cents >= 5)
	{
		cents -= 5;
		coins++;
	}
	while (cents >= 2)
	{
		cents -= 2;
		coins++;
	}
	while (cents >= 1)
	{
		cents -= 1;
		coins++;
	}

	return (coins);
}
