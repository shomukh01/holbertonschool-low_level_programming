#include <stdio.h>
#include <stdlib.h>

/**
	* f4 - gets random index using biggest char
	* @s: username
	* @len: length
	*
	* Return: index
	*/
int f4(char *s, int len)
{
	int max;
	int i;
	unsigned int r;

	max = s[0];
	i = 0;
	while (i < len)
	{
		if (max < s[i])
			max = s[i];
		i++;
	}
	srand(max ^ 14);
	r = rand();

	return (r & 63);
}

/**
	* f5 - gets index from sum of squares
	* @s: username
	* @len: length
	*
	* Return: index
	*/
int f5(char *s, int len)
{
	int sum = 0;
	int i = 0;

	while (i < len)
	{
		sum += s[i] * s[i];
		i++;
	}

	return (((unsigned int)sum ^ 239) & 63);
}

/**
	* f6 - gets random index
	* @s: username
	*
	* Return: index
	*/
int f6(char *s)
{
	int r = 0;
	int i = 0;

	while (i < s[0])
	{
		r = rand();
		i++;
	}

	return (((unsigned int)r ^ 229) & 63);
}

/**
	* main - generates key
	* @argc: argument count
	* @argv: arguments
	*
	* Return: 0
	*/
int main(int argc, char **argv)
{
	char key[7];
	int len, sum, i;
	long alpha[] = {
		0x3877445248432d41, 0x42394530534e6c37,
		0x4d6e706762695432, 0x74767a5835737956,
		0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850
	};

	(void)argc;
	for (len = 0; argv[1][len]; len++)
		;

	key[0] = ((char *)alpha)[(len ^ 59) & 63];

	sum = 0;
	for (i = 0; i < len; i++)
		sum += argv[1][i];
	key[1] = ((char *)alpha)[(sum ^ 79) & 63];

	sum = 1;
	for (i = 0; i < len; i++)
		sum *= argv[1][i];
	key[2] = ((char *)alpha)[(sum ^ 85) & 63];

	key[3] = ((char *)alpha)[f4(argv[1], len)];
	key[4] = ((char *)alpha)[f5(argv[1], len)];
	key[5] = ((char *)alpha)[f6(argv[1])];
	key[6] = '\0';

	printf("%s", key);

	return (0);
}
