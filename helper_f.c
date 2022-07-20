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
		return;

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
}
