#include "main.h"

/**
 * count_space - Counts necessary space for new string
 * @format: String to count space
 * @args: Arguments to verify
 *
 * Return: Count of necessary spacet to use
 */
unsigned int count_space(const char *format, va_list args)
{
	unsigned int i, count = 0;
	unsigned int (*op_func_space)(va_list);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				continue;

			op_func_space = get_op_func_space(format[i + 1]);
			if (op_func_space == NULL)
			{
				if (format[i + 1] != '%')
					count++;
				count++;
			}
			else
				count += op_func_space(args);
			i++;
			continue;
		}

		count++;
	}

	return (count);
}
