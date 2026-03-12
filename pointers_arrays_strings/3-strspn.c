#include "main.h"

/**
	* _strspn - gets length of prefix substring
	* @s: string to check
	* @accept: accepted characters
	*
	* Return: number of bytes in initial segment
	*/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		int found = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}

		if (found == 0)
			break;

		count++;
	}

	return (count);
}
