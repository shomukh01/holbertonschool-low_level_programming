#include "main.h"

/**
 * _strlen_recursion - returns length of string
 * @s: string
 * Return: length
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_pal - checks palindrome
 * @s: string
 * @i: start index
 * @j: end index
 * Return: 1 if palindrome, 0 otherwise
 */
int check_pal(char *s, int i, int j)
{
	if (i >= j)
		return (1);

	if (s[i] != s[j])
		return (0);

	return (check_pal(s, i + 1, j - 1));
}

/**
 * is_palindrome - checks if string is palindrome
 * @s: string
 * Return: 1 or 0
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	return (check_pal(s, 0, len - 1));
}
