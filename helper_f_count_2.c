#include "main.h"


/**
 * op_octal_count - Count space needed for an unsigned octal number
 * @args: Argument to be passed of type unsigned int
 *
 * Return: Space needed
 */
unsigned int op_octal_count(va_list args)
{
	unsigned int num, count;

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
	unsigned int num, count;

	num = va_arg(args, unsigned int);

	count = count_digits(num, 16);

	return (count);
}


/**
 * op_string_s_count - Count space needed for an string with hexadecimal numbers
 * @args: Argument to be passed of type char *
 *
 * Return: Space needed
 */
unsigned int op_string_s_count(va_list args)
{
	unsigned int i, count = 0;
	char *str = NULL;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
			count += 3;
		count++;
	}

	return (count);
}


/**
 * op_address_count - Count space needed for an address in hexadecimal
 * @args: Argument to be passed of type unsigned long int
 *
 * Return: Space needed
 */
unsigned int op_address_count(va_list args)
{
	unsigned int count = 2;
	unsigned long int address;

	address = va_arg(args, unsigned long int);

	count += bigger_count_digits(address, 16);

	return (count);
}
