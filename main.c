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
	int len, len1, len3;

	len = _printf("Binary: %b, Num: %d, Str: %s, Char: %c\n", 26, 4556, "HEllo", 'a');

	printf("Len _printf: %d\n", len);

	len1 = _printf("");
	printf("%d\n", len1);

	len3 = printf("");
	printf("%d\n", len3);

	return (0);
}
