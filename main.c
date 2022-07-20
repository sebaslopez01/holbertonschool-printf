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
	int i, j;

	i = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("%d\n", i);

	j = printf("%!\n");
	printf("%d\n", j);

	return (0);
}
