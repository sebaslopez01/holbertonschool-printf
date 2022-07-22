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
	int i;
	char *str = NULL;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*count] = str[i];
		(*count)++;
	}
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
	int num, num_temp, i, num_digits = 0;
	char *str = NULL;

	num = va_arg(args, int);
	num_temp = num;

	if (num_temp < 0)
	{
		num_digits++;
		num_temp *= -1;
	}

	for (; num_temp != 0; num_digits++)
		num_temp /= 10;

	str = malloc(sizeof(char) * num_digits + 1);
	if (!str)
		return;

	itoa(num, str, 10);

	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*count] = str[i];
		(*count)++;
	}

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
	unsigned int num, num_temp, i, num_digits = 0;
	char *str = NULL;

	num = va_arg(args, unsigned int);
	num_temp = num;

	for (; num_temp != 0; num_digits++)
		num_temp /= 2;

	str = malloc(sizeof(char) * num_digits + 1);
	if (!str)
		return;

	itoa(num, str, 2);

	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*count] = str[i];
		(*count)++;
	}

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
	unsigned int num, num_temp, i, num_digits = 0;
	char *str = NULL;

	num = va_arg(args, unsigned int);
	num_temp = num;

	for (; num_temp != 0; num_digits++)
		num_temp /= 10;

	str = malloc(sizeof(char) * num_digits + 1);
	if (!str)
		return;

	itoa(num, str, 10);
	
	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*count] = str[i];
		(*count)++;
	}

	free(str);
}
