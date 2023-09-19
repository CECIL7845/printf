#include "main.h"

/**
 * _printf - produces output according to a format
 * @*format - pointer to a format
 * char - character to a pointer
 *
 * Return: character to a pointer
 *
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

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			prn++;
		}
		else
		{
			format++;
			if (*format == '%')
			{
				write(1, format, 1);
				prn++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(srn, int);

				write(1, &c, 1);
				prn++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(srn, char *);

				if (str == NULL)
				{
				write(1, "(null)", 6);
				prn += 6;
				}
			}
			else
			{
				write(1, str, strlen(str));
				prn += strlen(str);
			}
		}
	}
	format++;
	va_end(srn);
	return (prn);
}
