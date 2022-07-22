#include "main.h"

/**
 * _printf - Prints with format
 * @format: Character string with directives
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args; 
	int i, count = 0;
	void (*op_func)(char *, va_list, int *);
	char *buffer = NULL;

	if (format == NULL)
		return (-1);
	va_start(args, formar = malloc(sizeof(char) * count_space(format, args) + 1);
	va_end(args);
	if (!buffer)
		return (0);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				continue;
			op_func = get_op_func(format[i + 1]);
			if (op_func == NULL)
			{
				buffer[count] = format[i];
				if (format[i + 1] != '%')
				{
					buffer[count + 1] = format[i + 1];
					count += 2;
				}
				else
					count++;
			}
			else
				op_func(buffer, args, &count);
			i++;
			continue;
		}
		buffer[count] = format[i];
		count++;
	}
	va_end(args);
	if (count == 0)
		return (-1);
	write(1, buffer, count);
	free(buffer);
	return (count);
}
