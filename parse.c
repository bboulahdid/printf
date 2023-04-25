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
	int i, j, k, p_func_result, printed_chars_size = 0;

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

			/* Skip format specifiers (c, s, %...) & spaces */
			if (p_funcs[j].type == NULL)
			{
				k = i + 1;
				while (format[k] != '\0')
				{
					if (format[k] == ' ')
						k++;
					else
					{
						i = k - 1;
						break;
					}
				}
			}
			else
				i++;
		}
	}

	return (printed_chars_size);
}

