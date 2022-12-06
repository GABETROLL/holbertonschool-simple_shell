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
 * *_strcpy - function that copies the string pointed including null byte
 * @dest: first pointer
 * @src: second pointer
 * Return: dest value (success)
 */
char *_strcpy(char *dest, char *src)
{
	int cpy;

	cpy = 0;
	while (src[cpy] != '\0')
	{
		dest[cpy] = src[cpy];
		cpy++;
	}
	dest[cpy] = '\0';
	return (dest);
}
