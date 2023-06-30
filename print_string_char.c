#include "main.h"

/**
 * print_string - Print a string
 * @string: The string to prrint
 * Return: The number of characters printed
 */
int print_string(const char *string)
{
	int len;

	len = strlen(string);

	write(1, string, len);

	return (len);

}

/**
 *  print_character - Print a character
 *  @character: The character to print
 *  Return: Return 1 for printing a charcter
 */
int print_character(char character)
{
	write(1, &character, 1);
	return (1); /** return 1 to */

}
