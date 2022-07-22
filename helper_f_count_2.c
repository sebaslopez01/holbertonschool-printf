#include "main.h"


/**
 * op_octal_count - Count space needed for an unsigned octal number
 * @args: Argument to be passed of type unsigned int
 *
 * Return: Space needed
 */
unsigned int op_octal_count(va_list args)
{
	unsigned int num, count = 0;

	num = va_arg(args, unsigned int);

	count = count_digits(num, 8);

	return (count);
}


/**
 * op_hexadecimal_count - Count space needed for an unsigned hexadecimal number
 * @args: Argument to be passed of type unsigned int
 *
 * Return: Space needed
 */
unsigned int op_hexadecimal_count(va_list args)
{
	unsigned int num, count = 0;

	num = va_arg(args, unsigned int);

	count = count_digits(num, 16);

	return (count);
}
