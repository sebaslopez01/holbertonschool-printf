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

	len = _printf("Binary: %b, Num: %d, Str: %R, Char: %c\n", 26, -4556, "Hola", 'a');

	printf("Len _printf: %d\n", len);

	return (0);
}
