#include "main.h"
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
