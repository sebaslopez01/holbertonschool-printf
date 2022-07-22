#include "main.h"

/**
 * get_op_func - Compares if a character is in the format_t struct
 * @c: Character to compare
 *
 * Return: A pointer to a function of type void (*f)(char *, va_list, int *)
 */
void (*get_op_func(char c))(char *, va_list, int *)
{
	int i;
	format_t ops[] = {
		{"c", op_char},
		{"s", op_string},
		{"d", op_number},
		{"i", op_number},
		{"b", op_binary},
		{"u", op_unsigned},
		{"o", op_octal},
		{NULL, NULL}
	};

	for (i = 0; ops[i].op != NULL; i++)
	{
		if (*ops[i].op == c)
			return (ops[i].f);
	}

	return (NULL);
}


/**
 * get_op_func_space - Compares if a character is in the format_c struct
 * @c: Character to compare
 *
 * Return: A pointer to a function of type unsigned int (*f)(va_list)
 */
unsigned int (*get_op_func_space(char c))(va_list)
{
	int i;
	format_c ops[] = {
		{"c", op_char_count},
		{"s", op_string_count},
		{"d", op_number_count},
		{"i", op_number_count},
		{"b", op_binary_count},
		{"u", op_unsigned_count},
		{"o", op_octal_count},
		{NULL, NULL}
	};

	for (i = 0; ops[i].op != NULL; i++)
	{
		if (*ops[i].op == c)
			return (ops[i].f);
	}

	return (NULL);
}
