#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _write_char(char c);
int _write_str(const char *str);
int handle_format_specifier(const char *format, va_list args);

#endif
