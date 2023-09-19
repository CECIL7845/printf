#include "main.h"

/**
 * _printf - a function that produces
 *  output according to a format.
 *
 *  @...: a variable number of strings to be printed
 *  @char:character to be printed
 *  @format: pointer to a format
 *
 *  Return: number of characters pointed
 */

int _printf(const char *format, ...)
{
	int prn = 0;

	va_list srn;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(srn, format);
	for (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			prn++;
		}
		else
		{
			format++;

			if (format == '%')
			{
				write(1, format, 1);
				prn++;
			}
			else if (format == 'c')
			{
				char c = va_arg(srn, int);

				write(1, &c, 1);
				prn++;
			}
			else if (format == 's')
			{
				int *str = va_arg(srn, int);

				write(1, str, strlen(str));
				prn++;
			}
			format++;
		}
	}
	va_end(srn);
	return (prn);
}
