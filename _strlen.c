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
