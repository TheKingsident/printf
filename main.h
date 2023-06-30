#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_integer(int number);
int print_unsigned_int(unsigned int unsigned_argument);
int print_string(const char *string);
int print_character(char character);
int print_hexadecimal(unsigned int hexadecimal_argument);
int print_uc_hexadecimal(unsigned int uc_hexadecimal_argument);
int print_octal(unsigned int octal_argument);
int print_address(void *pointer_argument);
int print_percentage(void);
int handle_format_specifier(char format_specifier, va_list args);

#endif /* MAIN_H */
