#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer to string
 * Return: return count (success)
 */
int _strlen(char *s)
{
	int count = 0, i = 0;

	while (s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

/**
 * equal_strings - Returns 1 if strings 'a' and 'b'
 * are equal, 0 otherwise.
 * @a: string
 * @b: string
 * Return: 1 if strings 'a' and 'b' are equal,
 * 0 otherwise
 */
int equal_strings(char *a, char *b)
{
	int a_index = 0;
	int b_index = 0;

	while (1)
	{
		if (a[a_index] != b[b_index])
			return (0);

		if (a[a_index] == '\0')
			return (1);

		a_index++;
		b_index++;
	}
}

