#include "main.h"

/**
 * str_tokens - Returns an array of pointers
 * to individual tokens in the 'str'
 * using "strtok(stdin_line, " \n")".
 *
 * The returned array is null poiinter-terminated.
 * It's also malloc'ed, and needs to be freed.
 * If it fails to malloc or if 'str is NULL,
 * str_tokens returns  NULL.
 *
 * @str: string with tokens separated by spaces
 *
 * Return: NULL pointer-terminated array of
 * pointers to tokens in the 'str' string
 * if the malloc call was successful,
 * NULL otherwise
 */
char **str_tokens(char *str)
{
	char **result;
	char *token;
	/*
	 * malloc token pointer array with the same length
	 * as 'str' to ensure an overflow doesn't happen:
	 */
	int str_len;
	int result_index = 0;

	if (!str)
		return (NULL);

	str_len = _strlen(str);

	result = malloc(sizeof(char *) * (str_len + 1));
	if (!result)
		return (NULL);

	token = strtok(str, " \n");
	while (token)
	{
		result[result_index] = token;
		result_index++;
		token = strtok(NULL, " \n");
	}
	result[result_index] = NULL;

	return (result);
}

