#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct format_t - Struct format_t
 *
 * @op: Operator of type char *
 * @f: The function associated to the operator
 */
typedef struct format_t
{
	char *op;
	void (*f)(char *, va_list, int *);
} format_t;

int _printf(const char *format, ...);

unsigned int count_space(const char *format, va_list args);

void fill_string(char *new_str, const char *format, va_list args);

int _printf2(const char *format, ...);

void (*get_op_func(char c))(char *, va_list, int *);

void op_string(char *buffer, va_list args, int *count);

void op_char(char *buffer, va_list args, int *count);

#endif /* MAIN_H */
