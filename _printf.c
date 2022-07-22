#include "main.h"


/**
 * _printf_helper - Fills the buffer with the data from the format
 * @format: Format to be used to fill the buffer
 * @args: Arguments to be use in the directives
 * @buffer: Buffer to fill
 *
 * Return: Count of bytes used to fullfill the buffer
 */
int _printf_helper(const char *format, va_list args, char *buffer)
{
	int i, count = 0;
	void (*op_func)(char *, va_list, int *);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				continue;
			op_func = get_op_func(format[i + 1]);
			if (op_func == NULL)
			{
				buffer[count++] = format[i];
				if (format[i + 1] != '%')
					buffer[count++] = format[i + 1];
			}
			else
				op_func(buffer, args, &count);
			i++;
			continue;
		}
		buffer[count++] = format[i];
	}

	return (count);
}



/**
 * _printf - Prints with format
 * @format: Character string with directives
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *buffer = NULL;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	buffer = malloc(sizeof(char) * count_space(format, args) + 1);
	if (!buffer)
		return (0);

	va_end(args);

	va_start(args, format);

	count = _printf_helper(format, args, buffer);
	if (count == 0)
		return (-1);

	va_end(args);

	write(1, buffer, count);

	free(buffer);

	return (count);
}
