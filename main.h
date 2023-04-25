#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct printer - a struct defining a printf function
 *
 * @type: the type of the arg to print
 * @print_func: the function to use to print the arg
 */
typedef struct print_t
{
	char *type;
	int (*print_func)(va_list);
} print_t;

int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percentage(va_list args);
int parse(const char *format, va_list args);

int _printf(const char *format, ...);

#endif /* MAIN_H */

