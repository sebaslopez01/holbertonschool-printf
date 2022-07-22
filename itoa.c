#include "main.h"


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


char *itoa(int num, char *buffer, int base)
{
	int digit, count = 0, temp_num = num;

	if (base < 2 || base > 32)
		return (buffer);
	if (num == 0)
	{
		buffer[count++] = '0';
		buffer[count] = '\0';
		return (buffer);
	}
	if (temp_num < 0)
		temp_num *= -1;

	while (temp_num != 0)
	{
		digit = temp_num % 10;

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
