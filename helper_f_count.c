#include "main.h"


/**
 * op_char_count - Count space necessary for a char type
 * @args: Arguments to be passed of type char
 *
 * Return: Space needed
 */
unsigned int op_char_count(va_list args)
{
	va_arg(args, int);
	return (1);
}


/**
 * op_string_count - Count space necessary for a string
 * @args: Arguments to be passed of type char *
 *
 * Return: Space needed
 */
unsigned int op_string_count(va_list args)
{
	unsigned int count = 0;
	char *str = NULL;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	count = _strlen(str);

	return (count);
}


/**
 * op_number_count - Count space needed for a number
 * @args: Arguments to be passed of type int
 *
 * Return: Space needed
 */
unsigned int op_number_count(va_list args)
{
	unsigned int count = 0;
	int num;

	num = va_arg(args, int);

	count = count_digits(num, 10);

	return (count);
}


/**
 * op_binary_count - Count space needed for a binary number
 * @args: Argument to be passed of type int
 *
 * Return: Space needed
 */
unsigned int op_binary_count(va_list args)
{
	unsigned int num, count = 0;

	num = va_arg(args, unsigned int);

	count = count_digits(num, 2);

	return (count);
}


/**
 * op_unsigned_count - Count space needed for an unsigned number
 * @args: Argument to be passed of type unsigned int
 *
 * Return: Space needed
 */
unsigned int op_unsigned_count(va_list args)
{
	unsigned int num, count = 0;

	num = va_arg(args, unsigned int);

	count = count_digits(num, 10);

	return (count);
}
