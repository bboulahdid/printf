#include "main.h"

/**
 * print_char - prints a char
 *
 * @args: the arguments list
 *
 * Return: 1
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 *
 * @args: the arguments list
 *
 * Return: the number of printed characters
 */
int print_string(va_list args)
{
	int i;
	char *str = va_arg(args, char *);

	str = (str != NULL) ? str : "(null)";

	for (i = 0; str[i] != '\0'; ++i)
		_putchar(str[i]);

	return (i);
}

/**
 * print_percentage - prints the % symbol
 *
 * @args: the arguments list
 *
 * Return: 1
 */
int print_percentage(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}

/**
 * print_integer - prints an int
 *
 * @args: the arguments list
 *
 * Return: the number's length
 */
int print_integer(va_list args)
{
	int int_length = 0, divider = 1;
	int num = va_arg(args, int);

	if (num < 0)
	{
		int_length += _putchar('-');
		num *= -1;
	}

	while (num / divider > 9)
		divider *= 10;

	while (divider != 0)
	{
		int_length += _putchar('0' + (num / divider));
		num %= divider;
		divider /= 10;
	}

	return (int_length);
}

