#include <unistd.h>
#include "main.h"

/**
 * _putchar - prints a character
 *
 * @c: the character to print
 *
 * Return: 1, or -1 in case of an error
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

