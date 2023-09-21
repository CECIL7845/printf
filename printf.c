#include "main.h"

/**
 * _write_char - Writes a character to stdout
 * @c: The character to write
 * Return: The number of characters written (1)
 */

int _write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _write_str - Writes a string to stdout
 * @str: The string to write
 * Return: The number of characters written
 */

int _write_str(char *str)
{
	int len = 0;

	if (str != NULL)
	{
		len = strlen(str);

		write(1, str, len);
	}
	else
	{
		write(1, "(null)", len);
	}
	return (len);
}

/**
 * _printf - a function that produces output according to a format
 * @format: Pointer to a format string
 *
 * Return: number of characters to be printed
 */

int _printf(const char *format, ...)
{
	int prn = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			break;

			prn += handle_format_specifier(format, args);
		}
		else
		{
			prn += _write_char(*format);
		}
		format++;
	}

	va_end(args);
	return (prn);
}

/**
 * handle_format_specifier - Handles format specifiers in the format string
 * @format: Pointer to the format string
 * @args: Argument list
 *
 * Return: The number of characters printed
 */
int handle_format_specifier(const char *format, va_list args)
{
	int prn = 0;

	if (*format == 'c')
	{
	int c = va_arg(args, int);
		prn += _write_char(c);
	}
	else if (*format == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
		{
			prn += _write_str("(null)");
		}
		else
		{
			prn += _write_str(str);
		}
	}
	else if (*format == '%')
	{
		prn += _write_char('%');
	}
	else
	{
		prn += _write_char('%');
		prn += _write_char(*format);
	}

	return (prn);
}
