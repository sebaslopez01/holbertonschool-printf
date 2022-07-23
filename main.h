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

void op_binary(char *buffer, va_list args, int *count);

void op_unsigned(char *buffer, va_list args, int *count);

void op_octal(char *buffer, va_list args, int *count);

void op_hexadecimal(char *buffer, va_list args, int *count);

void op_hexadecimal_l(char *buffer, va_list args, int *count);

void op_string_s(char *buffer, va_list args, int *count);

void op_address(char *buffer, va_list args, int *count);

unsigned int (*get_op_func_space(char c))(va_list);

unsigned int op_char_count(va_list args);

unsigned int op_string_count(va_list args);

unsigned int op_number_count(va_list args);

unsigned int op_binary_count(va_list args);

unsigned int op_unsigned_count(va_list args);

unsigned int op_octal_count(va_list args);

unsigned int op_hexadecimal_count(va_list args);

unsigned int op_string_s_count(va_list args);

unsigned int op_address_count(va_list args);

unsigned int count_digits(long int num, int base);

unsigned int bigger_count_digits(unsigned long int num, int base);

char *itoa(long int num, char *buffer, int base);

char *bigger_itoa(unsigned long int num, char *buffer, int base);

char *parse_unsigned_number(unsigned long int num, char *str, int base);

int _strlen(char *str);

void reverse_string(char *str);

void _strcpy(char *dest, char *origin, int *count);

void string_tolower(char *str);

#endif /* MAIN_H */
