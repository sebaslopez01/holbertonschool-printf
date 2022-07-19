#include "main.h"

/**
 * count_space - Count necessary space for new string
 * @format: String to count
 * @args: Arguments to verify
 *
 * Return: Count of necessary space to use
 */
unsigned int count_space(const char *format, va_list args)
{
    unsigned int i, count = 0;
    char *str_a = NULL;

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            switch (format[i + 1])
            {
            case 'c':
                va_arg(args, int);
                continue;
            case 's':
                str_a = va_arg(args, char *);
                if (!str_a)
                    str_a = "(null)";
                count += strlen(str_a) - 1;
                continue;
            case '%':
                i++;
                break;
            case '\0':
                continue;
            }
        }

        count++;
    }

    return (count);
}

/**
 * fill_string - Fill string with the value of the arguments
 * @new_str: New string to output with format
 * @format: String to use
 * @args: Arguments to fill in the new string
 *
 * Return: void
 */
void fill_string(char *new_str, const char *format, va_list args)
{
    unsigned int i, j, k = 0;
    char *str_a = NULL;

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            switch (format[i + 1])
            {
            case 'c':
                new_str[k] = (char)va_arg(args, int);
                continue;
            case 's':
                str_a = va_arg(args, char *);
                if (!str_a)
                    str_a = "(null)";
                for (j = 0; str_a[j] != '\0'; j++)
                {
                    new_str[k] = str_a[j];
                    k++;
                }
                k--;
                continue;
            case '%':
                i++;
                break;
            case '\0':
                continue;
            }
        }

        if (i > 0 && format[i - 1] == '%' && (format[i] == 'c' || format[i] == 's'))
            k++;
        else
        {
            new_str[k] = format[i];
            k++;
        }
    }

    new_str[k] = '\0';
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
    unsigned int count;
    char *new_str = NULL;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    count = count_space(format, args);

    if (count == 0)
        return (-1);

    va_end(args);

    new_str = malloc(sizeof(char) * count + 1);

    if (!new_str)
        return (0);

    va_start(args, format);

    fill_string(new_str, format, args);

    va_end(args);

    write(1, new_str, count);

    free(new_str);

    return (count);
}
