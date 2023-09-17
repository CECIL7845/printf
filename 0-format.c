#include <stdio.h>
#include <stdarg.h>

/**
 * int _printf - a function that produces
 *  output according to a format.
 *
 *  @...: a variable number of strings to be printed
 *
 *  Return: number of characters pointed
 */

int _printf(const char *format, ...)
{
	va_list fmt;

	va_start(fmt, format);
	if (format = "%"; format++)
	{
		format = va_arg(fmt, int);
		_printf("%%\n", *format);
	}
	int i = 0;
	if (i = 0; i < format; i++)
	{
		i = va_arg(fmt, int);
		_printf("%c\n", i);
		_printf("%s\n", "i");
	}
	
	va_end(i);
	return (i);
}
