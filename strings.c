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

/**
 * _strcat - function that concatenates two string
 * @dest: first array
 * @src: second array
 * Return: pointer to dest (success)
 */
char *_strcat(char *dest, char *src)
{
        int len, i;

        len = 0;
        i = 0;

        while (dest[len] != '\0')
                len++;

        while (src[i] != '\0')
        {
                dest[len] = src[i];
                len++;
                i++;
        }

        dest[len] = '\0';
        return (dest);
}

