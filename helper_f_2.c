#include "main.h"



/**
 * op_octal - Copies an unsigned octal to the buffer
 * @buffer: Buffer to copy characters
 * @args: Arguments of type unsigned int
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_octal(char *buffer, va_list args, int *count)
{
	unsigned int num;
	char *str = NULL;

	num = va_arg(args, unsigned int);

	str = parse_unsigned_number(num, str, 8);

	if (!str)
		return;

	_strcpy(buffer, str, count);

	free(str);
}


/**
 * op_hexadecimal - Copies an unsigned hexadecimal number
 * to the buffer
 * @buffer: Buffer to copy characters
 * @args: Arguments of type unsigned int
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_hexadecimal(char *buffer, va_list args, int *count)
{
	unsigned int num;
	char *str = NULL;

	num = va_arg(args, unsigned int);

	str = parse_unsigned_number(num, str, 16);

	if (!str)
		return;

	_strcpy(buffer, str, count);

	free(str);
}


/**
 * op_hexadecimal_l - Copies an unsigned hexadecimal number lowercase
 * to the buffer
 * @buffer: Buffer to copy characters
 * @args: Arguments of type unsigned int
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_hexadecimal_l(char *buffer, va_list args, int *count)
{
	unsigned int num;
	char *str = NULL;

	num = va_arg(args, unsigned int);

	str = parse_unsigned_number(num, str, 16);

	if (!str)
		return;

	string_tolower(str);

	_strcpy(buffer, str, count);

	free(str);
}
