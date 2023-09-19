#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - creating a new printf function
 * @format: format char
 * Return: Print char
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	va_list list;
	
	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
	}
		
