#ifndef MAIN_H
#define MAIN_H

/* Libraries */

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

/* Structures */

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

/**
 * struct format_c - Struct format_c
 *
 * @op: Operator of type char *
 * @f: The function to count the space needed of the operator
 */
typedef struct format_c
{
	char *op;
	unsigned int (*f)(va_list);
} format_c;


/* Prototypes */
int _printf(const char *format, ...);

int _printf_helper(const char *format, va_list args, char *buffer);

unsigned int count_space(const char *format, va_list args);

void (*get_op_func(char c))(char *, va_list, int *);

void op_string(char *buffer, va_list args, int *count);

void op_char(char *buffer, va_list args, int *count);

void op_number(char *buffer, va_list args, int *count);

unsigned int (*get_op_func_space(char c))(va_list);

unsigned int op_char_count(va_list args);

unsigned int op_string_count(va_list args);

unsigned int op_number_count(va_list args);

char *itoa(int num, char *buffer, int base);

void reverse_string(char *str);

#endif /* MAIN_H */
