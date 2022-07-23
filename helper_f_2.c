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


/**
 * op_string_s - Copies an string without its non printable characters
 * with \x followed by the ASCII code value in hexadecimal
 * @buffer: Buffer to copy characters
 * @args: Arguments of type char * or hexadecimal
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_string_s(char *buffer, va_list args, int *count)
{
	int i;
	char *str = NULL, hex_num[3];

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_strcpy(buffer, "\\x", count);

			itoa(str[i], hex_num, 16);

			if (_strlen(hex_num) == 1)
				buffer[(*count)++] = '0';

			_strcpy(buffer, hex_num, count);

			continue;
		}

		buffer[(*count)++] = str[i];
	}
}


/**
 * op_address - Copies an address value in hexadecimal to the buffer
 * @buffer: Buffer to copy characters
 * @args: Arguments of type unsigned long int
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_address(char *buffer, va_list args, int *count)
{
	unsigned long int address;
	char *str = NULL;

	address = va_arg(args, unsigned long int);

	buffer[(*count)++] = '0';
	buffer[(*count)++] = 'x';

	str = parse_unsigned_number(address, str, 16);

	if (!str)
		return;

	_strcpy(buffer, str, count);

	free(str);
}
