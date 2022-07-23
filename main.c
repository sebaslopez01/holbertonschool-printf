#include <limits.h>
#include <stdio.h>
#include "main.h"


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;

	len = _printf("Binary: %b, Num: %d, Str: %s, Char: %c\n", 26, 4556, "HEllo", 'a');

	printf("Len _printf: %d\n", len);

	_printf("%S\n", "Best\nSchool");

	return (0);
}
