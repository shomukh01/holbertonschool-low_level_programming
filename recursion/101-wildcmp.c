#include "main.h"

/**
 * wildcmp - compares two strings with wildcard *
 * @s1: first string
 * @s2: second string
 * Return: 1 if identical, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) != '\0' && *s1 == '\0')
			return (0);

		return (wildcmp(s1, s2 + 1) ||
			(*s1 && wildcmp(s1 + 1, s2)));
	}

	if (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (1);

		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0);
}
