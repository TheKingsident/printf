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
				char buffer[20]; /** Char to store the integer/number as a string */
				int num;

				number_argument = va_arg(function_arguments, int);

				num = sprintf(buffer, "%d", number_argument);
				write(1, buffer, num); } /** Write string to stdout */

			else if (format_specifier == 'c')
			{
				char character_arguments;
				character_arguments = (char)va_arg(function_arguments, int);
				write(1, &character_arguments, 1); } /** Writes the character to stdout */
			else if (format_specifier == 's')
			{
				char* string_arguments;
				int len;

				string_arguments = va_arg(function_arguments, char*);
				len = strlen(string_arguments);
				write(1, string_arguments, len); } /** write the strimg to stdout */
		}
	}



	va_end(function_arguments);
	return (character_count);
}
