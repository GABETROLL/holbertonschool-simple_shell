#include "main.h"

/**
 * _strcmp - compares two string
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: if are the same 0 otherwise negative or positive value
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strncmp - compares n bytes of two strings
 * @s1: character string
 * @s2: character string
 * @n: number of byte
 * Return: zero if string are the same
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	do {
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		if (*s1++ == 0)
			break;
	} while (--n != 0);
	return (0);
}
