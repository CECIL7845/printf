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
int _write_str(const char *str)
{
	if (str != NULL)
	{
		return (write(1, str, strlen(str)));
	}
	else
	{
		return (write(1, "(null)", 6));
	}
}

/**
 * _printf - a function that produces output according to a format
 * @format: Pointer to a format string
 *
 * Return: Number of characters to be printed
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
			{
				break;
			}

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
 * Return: number of characters to be printed
 */
int handle_format_specifier(const char *format, va_list args)
{
	int prn = 0;

	switch (*format)
	{
		case 'c':
		{
			int c = va_arg(args, int);

			prn += _write_char(c);
			break;
		}
		case 's':
		{
			const char *str = va_arg(args, const char *);

			if (str == NULL)
			{
				prn += _write_str("(null)");
			}
			else
			{
				prn += _write_str(str);
			}
			break;
		}
		case '%':
		{
			prn += _write_char('%');
			break;
		}
		default:
		{
			prn += _write_char('%');
			prn += _write_char(*format);
			break;
		}
	}
	format++;

	return (prn);
}
