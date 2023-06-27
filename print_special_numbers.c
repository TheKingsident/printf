#include "main.h"

int print_hexadecimal(unsigned int hexadecimal_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%x", hexadecimal_argument);
	write(1, buffer, num);

	return (num);

}

int print_uc_hexadecimal(unsigned int uc_hexadecimal_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%X", uc_hexadecimal_argument);
	write(1, buffer, num);

	return (num);
}

int print_octal(unsigned int octal_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%o", octal_argument);
	write(1, buffer, num);

	return (num);

}

int print_address(void* pointer_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%p", pointer_argument);
	write(1, buffer, num);

	return (num);

}

int print_percentage()
{
	write(1, "%", 1);
	return (1);
}
