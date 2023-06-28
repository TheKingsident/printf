#include "main.h"

/**
 * _printf - work like std printf function
 * @format: Format of string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i;
	int character_count;
	va_list function_arguments;

	va_start(function_arguments, format);

	character_count = 0;

	/** Iterate through the format string and handle format specifiers */
	for (i = 0; format[i] != '\0'; i++)
	{
		/** Output regular characters */
		if (format[i] != '%')
		{
			write(1, &format[i], 1); /** Writes a single
						  * character to stdout
						  */
			character_count++; }
		else
		{
			/** Handle format specifiers */
			i++; /** To get the next character after '%' */
			character_count += handle_format_specifier(format[i],
					function_arguments);

		}
	}
	va_end(function_arguments);
	return (character_count);
}

/**
 *  handle_format_specifier - Handle the various format cases
 *  @format_specifier: The format specifier
 *  @args: Contains the arguments
 *  Return: The length of printed characters
 */
int handle_format_specifier(char format_specifier, va_list args)
{

	switch (format_specifier)
	{
		case 'd':
		case 'i':
			return (print_integer(va_arg(args, int)));

		case 'u':
			return (print_unsigned_int(va_arg(args, unsigned int)));

		case 'c':
			return (print_character((char)va_arg(args, int)));

		case 's':
			return (print_string(va_arg(args, char*)));

		case 'x':
			return (print_hexadecimal(va_arg(args, unsigned int)));

		case 'X':
			return (print_uc_hexadecimal(va_arg(args, unsigned int)));

		case 'o':
			return (print_octal(va_arg(args, unsigned int)));

		case 'p':
			return (print_address(va_arg(args, void*)));

		case '%':
			return (print_percentage());

		default:
			write(1, "%", 1);
			write(1, &format_specifier, 1);
			return (2); }

}
