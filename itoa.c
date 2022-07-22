#include "main.h"

/**
 * reverse_string - Reverses the order of an array of chars
 * @str: Array of chars to reverse
 *
 * Return: void
 */
void reverse_string(char *str)
{
	int i, len = strlen(str);
	char temp;

	for (i = 0; i < len / 2; i++)
	{
		temp = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = temp;
	}
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
