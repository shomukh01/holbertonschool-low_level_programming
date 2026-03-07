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
char sep[] = " \t\n,;.!?\"(){}";
int j;

while (str[i])
{
if (i == 0)
{
if (str[i] >= 'a' && str[i] <= 'z')
str[i] -= 32;
}
else
{
for (j = 0; sep[j]; j++)
{
if (str[i - 1] == sep[j])
{
if (str[i] >= 'a' && str[i] <= 'z')
str[i] -= 32;
}
}
}
i++;
}
return (str);
}
