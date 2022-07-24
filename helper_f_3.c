#include "main.h"

/**
 * op_reverse - Copies an string in reverse order to the buffer
 * @buffer: Buffer to copy characters
 * @args: Arguments of type char *
 * @count: Qunatity to affect
 *
 * Return: void
 */
void op_reverse(char *buffer, va_list args, int *count)
{
	int i = 0;
	char *str = NULL, *new_str = NULL;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	new_str = malloc(sizeof(char) * _strlen(str) + 1);
	if (!new_str)
		return;

	_strcpy(new_str, str, &i);

	reverse_string(new_str);

	_strcpy(buffer, new_str, count);

	free(new_str);
}
