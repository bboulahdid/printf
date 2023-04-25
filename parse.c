#include "main.h"

/**
 * parse - parse the format with the provided args & outputs to STDOUT
 *
 * @format: the format to use to produce the output
 * @args: the arguments list
 *
 * Return: the number of printed characters
 */
int parse(const char *format, va_list args)
{
	int i, j, p_func_result, printed_chars_size = 0;

	print_t p_funcs[] = {
			{"c", print_char},
			{"s", print_string},
			{"%", print_percentage},
			{NULL, NULL}};

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars_size++;
		}
		else
		{
			for (j = 0; p_funcs[j].type != NULL; j++)
			{
				if (p_funcs[j].type[0] == format[i + 1])
				{
					p_func_result = p_funcs[j].print_func(args);

					if (p_func_result == -1)
						return (-1);

					printed_chars_size += p_func_result;
					break;
				}
			}

			if (p_funcs[j].type == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i + 1]);
					printed_chars_size += 1;
				}
			}

			/* Skip format specifiers: c, s, %... */
			i++;
		}
	}

	return (printed_chars_size);
}

