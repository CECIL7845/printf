#include "main.h"

/**
 * _printf - print function that handles conversion specifiers
 * @format: format string.
 * @...: number of arguments.
 * Return: prints character
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, printed_chars = 0;
	int length = 0;
	int j = length - 1;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			int num = va_arg(args, int);
			char buffer[20];
			int length = 0;

			if (num == 0)
			{
				buffer[length++] = '0';
			}
			else
			{
				if (num < 0)
				{
					write(1, "-", 1);
					num = -num;
					printed_chars++;
				}
				while (num > 0)
				{
					buffer[length++] = num % 10 + '0';
					num /= 10;
				}

				while (j >= 0)
				{
					j--;
				}
				{
					write(1, &buffer[j], 1);
					printed_chars++;
				}
			}

			i += 2
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
			i++;
		}
	}

	va_end(args);
	return (printed_chars);
}
