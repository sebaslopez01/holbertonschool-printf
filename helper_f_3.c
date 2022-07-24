#include "main.h"

/**
 * op_reverse - Copies an string in reverse order to the buffer
 * @buffer: Buffer to copy characters
 * @args: Arguments of type char *
 * @count: Quantity to affect
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


/**
 * op_rot13 - Copies an string with 13rot encryption pattern
 * @buffer: Buffer to copy characters
 * @args: Arguments of type char *
 * @count: Quantity to affect
 *
 * Return: void
 */
void op_rot13(char *buffer, va_list args, int *count)
{
	int i;
	char *str = NULL;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 65 && str[i] <= 77) || (str[i] >= 97 && str[i] <= 109))
			buffer[(*count)++] = str[i] + 13;
		else if ((str[i] >= 78 && str[i] <= 90) || (str[i] >= 110 && str[i] <= 122))
			buffer[(*count)++] = str[i] - 13;
		else
			buffer[(*count)++] = str[i];
	}
}
