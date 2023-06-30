#include "main.h"

/**
 * print_integer - Write an integer
 * @number:  Number argument
 * Return: The number of written numbers
 */
int print_integer(int number)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%d", number);
	write(1, buffer, num);
	return (num); /** Return number of characters printed */
}

/**
 * print_unsigned_int - Writes unsigned integer
 * @unsigned_argument: Unsigned integer argument
 * Return: The number of written characters
 */
int print_unsigned_int(unsigned int unsigned_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%u", unsigned_argument);
	write(1, buffer, num);
	return (num);

}
