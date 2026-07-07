#include "variadic_functions.h"

/**
 * print_char - prints a character
 * @ap: argument list
 */
void print_char(va_list *ap)
{
printf("%c", va_arg(*ap, int));
}

/**
 * print_int - prints an integer
 * @ap: argument list
 */
void print_int(va_list *ap)
{
printf("%d", va_arg(*ap, int));
}

/**
 * print_float - prints a float
 * @ap: argument list
 */
void print_float(va_list *ap)
{
printf("%f", va_arg(*ap, double));
}

/**
 * print_string - prints a string
 * @ap: argument list
 */
void print_string(va_list *ap)
{
char *s;

s = va_arg(*ap, char *);
if (!s)
s = "(nil)";
printf("%s", s);
}

/**
 * print_all - prints anything
 * @format: list of argument types
 */
void print_all(const char * const format, ...)
{
int i, j;
char *sep;
va_list ap;
printer_t p[] = {
{'c', print_char},
{'i', print_int},
{'f', print_float},
{'s', print_string},
{0, NULL}
};

sep = "";
va_start(ap, format);
i = 0;
while (format && format[i])
{
j = 0;
while (p[j].c)
{
if (format[i] == p[j].c)
{
printf("%s", sep);
p[j].f(&ap);
sep = ", ";
}
j++;
}
i++;
}
va_end(ap);
printf("\n");
}
