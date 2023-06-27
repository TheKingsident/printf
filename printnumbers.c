#include "main.h"


int print_integer(int number)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%d", number);
	write(1, buffer, num);
	return (num); /** Return number of characters printed */
}

int print_unsigned_int(unsigned int unsigned_argument)
{
	char buffer[20];
	int num;

	num = sprintf(buffer, "%u", unsigned_argument);
	write(1, buffer, num);
	return (num);

}
