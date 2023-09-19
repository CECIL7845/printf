#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

/* MACRO DEFINITIONS */

/*  FLAGS MACRO DEFINTION  */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 1

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* SIZE MACRO DEFINITION */
#define S_LONG 2
#define S_SHORT 1

int _printf(const char *format, ...);

#endif
