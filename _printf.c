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
	char format_specifier;
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

			format_specifier = format[i]; /** assign either c, d, i or s */

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
				character_count += print_character(character_arguments); } /** Writes the character to stdout */
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
				character_count += 2; }
		}
	}



	va_end(function_arguments);
	return (character_count);
}
