#include "main.h"

/**
 * _write_char - Writes a character to stdout
 * @c: The character to write
 *
 * Return: The number of characters written (1)
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _write_str - Writes a string to stdout
 * @str: The string to write
 *
 * Return: The number of characters written
 */
int _write_str(char *str)
{
	int len = 0;

	if (str)
	{
		len = strlen(str);

		write(1, str, len);
	}
	else
	{
		len = 6;
		write(1, "(null)", len);
	}
	return (len);
}

/**
 * _printf - Produces output according to a format
 * @format: Pointer to a format string
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int prn = 0;
	va_list srn;

	if (format == NULL)
		return (-1);

	va_start(srn, format);

	while (*format)
	{
		if (*format != '%')
		{
			prn += _write_char(*format);
		}
		else
		{
			format++;
			if (*format == '%')
			{
				prn += _write_char(*format);
			}
			else if (*format == 'c')
			{
				char c = va_arg(srn, int);

				prn += _write_char(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(srn, char *);

				prn += _write_str(str);
			}
		}
		format++;
	}
	va_end(srn);
	return (prn);
}
