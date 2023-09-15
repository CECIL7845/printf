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
	int i = 0;
	for (i = 0; i < format; i++)
	{
		i = va_arg(fmt, int);
	}
	
	va_end(i);
	return (i);
}


/**
 * main -Entry point
 *
 * Return:0
 */

int main(void)
{
	printf("character = '%c'/n", ABCD);
	printf("string = '%s'/n", " ");
	printf("percent = '%%'/n", %);
	return (0);
}
