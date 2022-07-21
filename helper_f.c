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


void op_number(char *buffer, va_list args, int *count)
{
	int n, n_temp, i, num_digits = 0;
	char *str = NULL;

	n = va_arg(args, int);
	n_temp = n;

	if (n_temp < 0)
	{
		num_digits++;
		n_temp *= -1;
	}
	
	num_digits += (int)floor(log(n_temp) / log(10)) + 1;

	str = malloc(sizeof(char) * num_digits + 1);
	if (!str)
		return;

	itoa(n, str, 10);

	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*count] = str[i];
		(*count)++;
	}

	free(str);
}
