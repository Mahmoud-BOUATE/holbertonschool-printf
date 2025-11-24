#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"
/**
*/
int _putstr(const char *txt)
{
int i, count;

while (txt[i] != '\0')
{
    write(1,&txt[i],1);
    i++;
}
return (count);
}
/**
*/
int _printf(const char *format, ...)
{
int i = 0;
int count = 0;
char c;
char *str;

va_list args;
va_start(args,format);

if (format == NULL)
return (-1);



while (format[i] != '\0')
{
    if (format[i] == '%')
    {
    count++;
    i++;   
    if (format[i] == '\0')
    break;
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
        count+= _putstr(str);
    }
    
    else
    {
    write(1, "%", 1);
    write(1, &format[i], 1);
    count += 2;
    }
    i++; /* on a consommé le caractère de format */
    continue;
    }
    
    write(1, &format[i] ,1);
    count ++;
    i++;
    }
    va_end(args);
    return (count);
}





