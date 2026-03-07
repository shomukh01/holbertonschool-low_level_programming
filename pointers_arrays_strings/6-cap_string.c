#include "main.h"

/**
* cap_string - capitalizes all words of a string
* @str: string
*
* Return: pointer to the string
*/
char *cap_string(char *str)
{
int i = 0;
int cap = 1;

while (str[i])
{
if (str[i] == ' '  str[i] == '\t'  str[i] == '\n' ||
str[i] == ','  str[i] == ';'  str[i] == '.' ||
str[i] == '!'  str[i] == '?'  str[i] == '"' ||
str[i] == '('  str[i] == ')'  str[i] == '{' ||
str[i] == '}')
{
cap = 1;
}
else if (cap && str[i] >= 'a' && str[i] <= 'z')
{
str[i] -= 32;
cap = 0;
}
else
{
cap = 0;
}
i++;
}
return (str);
}
