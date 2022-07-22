#include "main.h"


/**
 * count_digits - Count number of digits of a number
 * @num: Number to count
 * @base: Base to use
 *
 * Return: Number of digits
 */
unsigned int count_digits(long int num, int base)
{
	unsigned int num_digits = 0;

	if (num < 0)
		num_digits++;

	for (; num != 0; num_digits++)
		num /= base;

	return (num_digits);
}


/**
 * parse_unsigned_number - Converts an unsigned number to string
 * @num: Num to parse
 * @str: String to save parsed number
 * @base: Base to use
 *
 * Return: Number converted to strin
 */
char *parse_unsigned_number(unsigned int num, char *str, int base)
{
	unsigned int num_digits = count_digits(num, base);

	str = malloc(sizeof(char) * num_digits + 1);
	if (!str)
		return (NULL);

	str = itoa(num, str, base);
	if (!str)
		return (NULL);

	return (str);
}


/**
 * itoa - Fill a buffer of chars with an int value
 * @num: Number to convert to a string
 * @buffer: Buffer to fill
 * @base: Base to use for the conversion
 *
 * Return: Number converted to string
 */
char *itoa(long int num, char *buffer, int base)
{
	long int digit, temp_num = num;
	int count = 0;

	if (base < 2 || base > 32)
		return (buffer);
	if (num == 0)
	{
		buffer[count++] = '0';
		buffer[count] = '\0';
		return (buffer);
	}

	while (temp_num != 0)
	{
		digit = temp_num % base;

		if (digit < 0)
			digit *= -1;

		if (digit >= 10)
			buffer[count++] = (digit - 10) + 'A';
		else
			buffer[count++] = digit + '0';

		temp_num /= base;
	}

	if (num < 0 && base == 10)
		buffer[count++] = '-';

	buffer[count] = '\0';

	reverse_string(buffer);

	return (buffer);
}
