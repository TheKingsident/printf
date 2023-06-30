#include "main.h"

/**
 * print_hexadecimal - Writes a hexadecimal number
 * @hexadecimal_argument: The hexadecimal argument
 * Return: The number of written characters
 */
int print_hexadecimal(unsigned int hexadecimal_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%x", hexadecimal_argument);
	write(1, buffer, num);

	return (num);

}

/**
 * print_uc_hexadecimal -Writes upper case hexadecimal number
 * @uc_hexadecimal_argument: The upper case hex argument
 * Return: The number of written characters
 */
int print_uc_hexadecimal(unsigned int uc_hexadecimal_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%X", uc_hexadecimal_argument);
	write(1, buffer, num);

	return (num);
}

/**
 * print_octal - Writes an octal number
 * @octal_argument: The octal argument
 * Return: he number of written characters
 */
int print_octal(unsigned int octal_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%o", octal_argument);
	write(1, buffer, num);

	return (num);

}

/**
 * print_address - Writes address
 * @pointer_argument: Pointer argument
 * Return: The number of written characters
 */
int print_address(void *pointer_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%p", pointer_argument);
	write(1, buffer, num);

	return (num);

}

/**
 * print_percentage - Writes percentage
 * Return: Returns 1 for every written character
 */
int print_percentage(void)
{
	write(1, "%", 1);
	return (1);
}
