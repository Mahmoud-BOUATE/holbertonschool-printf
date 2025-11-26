#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
 * _printf - custom implementation of printf
 * @format: format string
 * Return: number of characters printed
 * Description: This function handles %c, %s, and %% format specifiers.
 */
int _printf(const char *format, ...)
{
int i = 0, count = 0, nbr;
char c, *str;

va_list args;


if (format == NULL)
return (-1);

va_start(args, format);

while (format[i] != '\0')
{
	if (format[i] == '%')
	{
		i++;
		if (format[i] == '\0')
		{
			va_end(args);
			return (-1);
		}
		if (format[i] == '%')
		{
			write(1, "%", 1);
			count++;
		}
		else if (format[i] == 'c')
		{
			c = va_arg(args, int);
			write(1, &c, 1);
			count++;
		}
		else if (format[i] == 's')
		{
			str = va_arg(args, char *);
			count += _putstr(str);
		}
		else if (format[i] == 'd' || format[i] == 'i')
		{
			nbr = va_arg(args, int);
			count += _putsnbr(nbr);
		}
		else
		{
			write(1, "%", 1);
			write(1, &format[i], 1);
			count += 2;
		}
		i++;
	}
	else
	{
		write(1, &format[i], 1);
		count++;
		i++;
	}
}
va_end(args);
return (count);
}
