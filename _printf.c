#include "main.h"

/**
 * _printf - produces output according to a format
 *
 * @format: the format to use to produce output
 *
 * Return: the number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars_size;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	printed_chars_size = parse(format, args);

	va_end(args);

	return (printed_chars_size);
}

