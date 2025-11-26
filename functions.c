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

	if (!txt)
		txt = "(null)";
	while (txt[i] != '\0')
	{
		write(1, &txt[i], 1);
		i++;
	}
return (i);
}
/**
 * _putsnbr - helper function to print a number
 * @n: number to print
 * Return: number of characters printed
 */
int _putsnbr(long int n)
{
	char c;
	int count = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += _putsnbr(n / 10);
	}
	c = '0' + (n % 10);
	write(1, &c, 1);
	count++;
	return (count);
}
