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
		{NULL, NULL}
	};

	for (i = 0; ops[i].op != NULL; i++)
	{
		if (*ops[i].op == c)
			return (ops[i].f);
	}

	return (NULL);
}
