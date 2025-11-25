#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"
/**
 * _putstr - helper function to print a string
 * @txt: string to print
 * Return: number of characters printed
 */
int _putstr(const char *txt)
{
int i = 0;
int count = 0;

	if (!txt)
		txt = "(null)";
	while (txt[i] != '\0')
	{
		write(1, &txt[i], 1);
		i++;
		count++;
	}
return (count);
}

/**
 *
 */
int putsnbr(int n)
{
	while (n > 0)
	{
		if (n <= 9)
		{
			write(1, &n, 1);
		}
	}
}
/**
 * _printf - custom implementation of printf
 * @format: format string
 * Return: number of characters printed
 * Description: This function handles %c, %s, and %% format specifiers.
 */
int _printf(const char *format, ...)
{
int i = 0;
int count = 0;
int nbr = 0;
char c;
char *str;

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
		else if (format[i] == 'i' || format[i] == 'd')
		{
			nbr = va_arg(args, int);
			count += putsnbr(nbr);
		}
		else
		{
			write(1, "%", 1);
			write(1, &format[i], 1);
			count += 2;
		}
		i++;
		continue;
	}
	write(1, &format[i], 1);
	count++;
	i++;
}
va_end(args);
return (count);
}


int main(void)
{
	int x = 8;
	_printf("%d", x);
	return (0);
}