#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_str - write to stdout a string
 * @s: string that will be write
 *
 * Return: 0 in succes.
 */

int print_str(char *s)
{
	unsigned long int i = 0;

	while (*(s + i) != '\0')
	{
		_putchar(*(s + i));
		i++;
	}
	return (0);
}


/**
 * _printf - work like std printf function
 * @format: format of string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned int long i = 0, c = 0;
	va_list a;
	char *s;

	va_start(a, format);
	if (format == NULL)
	{
		_putchar('\n');
		return (0);
	}
	while (i < strlen(format))
	{
		if (*(format + i) == '%')
		{
			i++;
			switch (*(format + i))
			{
			case 'c':
				_putchar(va_arg(a, int));
				c++;
				break;
			case 's':
				s = va_arg(a, char*);
				print_str(s);
				c = c + strlen(s);
				break;
			default:
				break;
			}
		}
		else
		{
			_putchar(*(format + i));
			c++;
		}
		i++;
	}
	_putchar('\n');
	va_end(a);
	c++;
	return (c);
}
