#include "main.h"

/**
 * op_string - Copies string to buffer
 * @buffer: Buffer to copy data
 * @args: Arguments of type char *
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_string(char *buffer, va_list args, int *count)
{
	char *str = NULL;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	_strcpy(buffer, str, count);
}


/**
 * op_char - Copies character to buffer
 * @buffer: Buffer to copy character
 * @args: Arguments of type char *
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_char(char *buffer, va_list args, int *count)
{
	char c;

	c = (char)va_arg(args, int);

	buffer[*count] = c;
	(*count)++;
}


/**
 * op_number - Copies a number to buffer
 * @buffer: Buffer to copy characters
 * @args: Arguments of type int
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_number(char *buffer, va_list args, int *count)
{
	int num;
	unsigned int num_digits;
	char *str = NULL;

	num = va_arg(args, int);

	num_digits = count_digits(num, 10);

	str = malloc(sizeof(char) * num_digits + 1);
	if (!str)
		return;

	itoa(num, str, 10);

	_strcpy(buffer, str, count);

	free(str);
}


/**
 * op_binary - Copies a binary number to buffer
 * @buffer: Buffer to copy characters
 * @args: Arguments of type unsigned int
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_binary(char *buffer, va_list args, int *count)
{
	unsigned int num;
	char *str = NULL;

	num = va_arg(args, unsigned int);

	str = parse_unsigned_number(num, str, 2);

	if (!str)
		return;

	_strcpy(buffer, str, count);

	free(str);
}


/**
 * op_unsigned - Copies an unsigned number to the buffer
 * @buffer: Buffer to copy characters
 * @args: Arguments of type unsigned int
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_unsigned(char *buffer, va_list args, int *count)
{
	unsigned int num;
	char *str = NULL;

	num = va_arg(args, unsigned int);

	str = parse_unsigned_number(num, str, 10);

	if (!str)
		return;

	_strcpy(buffer, str, count);

	free(str);
}
