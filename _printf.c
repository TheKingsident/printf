#include "main.h"

/**
 * _printf - work like std printf function
 * @format: Format of string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i;
	/**char format_specifier; */
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
			write(1, &format[i], 1); /** Writes a single character to stdout */
			character_count++; } /** Increment the character count for printed character */
		else
		{
			/** Handle format specifiers */
			i++; /** To get the next character after '%' */
			character_count += handle_format_specifier(format[i], function_arguments);

			/** format_specifier = format[i]; 

			if (format_specifier == 'd' || format_specifier == 'i')
			{
				int number_argument;

				number_argument = va_arg(function_arguments, int);
				character_count += print_integer(number_argument);  }
			
			else if (format_specifier == 'u')
			{
				unsigned int unsigned_argument;

				unsigned_argument = va_arg(function_arguments, unsigned int);
				character_count += print_unsigned_int(unsigned_argument); }

			else if (format_specifier == 'c')
			{
				char character_arguments;
				character_arguments = (char)va_arg(function_arguments, int);
				character_count += print_character(character_arguments); }
	
			else if (format_specifier == 's')
			{
				char* string_arguments;

				string_arguments = va_arg(function_arguments, char*);
				character_count += print_string(string_arguments); }
			else if (format_specifier == 'x')
			{
				unsigned int hexadecimal_arguments;

				hexadecimal_arguments = va_arg(function_arguments, unsigned int);
				character_count += print_hexadecimal(hexadecimal_arguments); }
			else if (format_specifier == 'X')
			{
				unsigned int uc_hexadecimal_arguments;

				uc_hexadecimal_arguments = va_arg(function_arguments, unsigned int);
				character_count += print_uc_hexadecimal(uc_hexadecimal_arguments); }
			else if (format_specifier == 'o')
			{
				unsigned int octal_arguments;

				octal_arguments = va_arg(function_arguments, unsigned int);
				character_count += print_octal(octal_arguments); }
			else if (format_specifier == 'p')
			{
				void* pointer_arguments;

				pointer_arguments = va_arg(function_arguments, void*);
				character_count += print_address(pointer_arguments); }
			else if (format_specifier == '%')
			{
				character_count += print_percentage(); }
			else
			{
				write(1, &format[i - 1], 1);
				write(1, &format[i], 1);
				character_count += 2; } */
		}
	}



	va_end(function_arguments);
	return (character_count);
}

/**
 *  handle_format_specifier - Handle the various format cases
 *  @format_specifier: The format specifier
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
