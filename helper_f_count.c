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

	while (str[count] != '\0')
		count++;

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

	if (num < 0)
		count++;

	for (; num != 0; count++)
		num /= 10;

	return (count);
}
