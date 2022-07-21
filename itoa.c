#include "main.h"
#include <math.h>

char *itoa(int num, char *buffer, int base)
{
	int base_val, num_val, curr = 0, num_digits = 0;

	if (num == 0)
	{
		buffer[curr++] = '0';
		buffer[curr] = '\0';
		return (buffer);
	}
	if (num < 0)
	{
		if (base == 10)
		{
			num_digits++;
			buffer[curr] = '-';
			curr++;
			num *= -1;
		}
		else
			return (NULL);
	}
	num_digits += (int)floor(log(num) / log(base)) + 1;

	while (curr < num_digits)
	{
		base_val = (int)pow(base, num_digits - 1 - curr);
		num_val = num / base_val;
		buffer[curr] = num_val + '0';
		curr++;
		num -= base_val * num_val;
	}
	buffer[curr] = '\0';
	return (buffer);
}
