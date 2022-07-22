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

	len = _printf("Num: %d, Str: %s, Char: %c\n", -2345, "Hello", 'a');

	printf("Len _printf: %d\n", len);

	return (0);
}
