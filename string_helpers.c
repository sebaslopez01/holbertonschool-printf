#include "main.h"


/**
 * _strcpy - Copy a origin string to a destination string
 * @dest: Destination to copy
 * @origin: Origin to take for copy to dest
 * @count: Quantity to affect
 *
 * Return: void
 */
void _strcpy(char *dest, char *origin, int *count)
{
	int i;

	for (i = 0; origin[i] != '\0'; i++)
	{
		dest[*count] = origin[i];
		(*count)++;
	}
}


/**
 * _strlen - Count the length of a string
 * @str: String to count
 *
 * Return: Length of str
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}


/**
 * reverse_string - Reverses the order of an array of chars
 * @str: Array of chars to reverse
 *
 * Return: void
 */
void reverse_string(char *str)
{
	int i, len = _strlen(str);
	char temp;

	for (i = 0; i < len / 2; i++)
	{
		temp = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = temp;
	}
}


/**
 * string_tolower - Changes all uppercase letters of a string to lowercase
 * @str: String to affect
 *
 * Return: void
 */
void string_tolower(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
	}
}
