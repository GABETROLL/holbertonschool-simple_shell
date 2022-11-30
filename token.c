#include "main.h"

/**
 * stdin_tokens - Reads line from stdin
 * and returns an array of pointers to
 * individual tokens in the stdin line.
 *
 * The returned array is null poiinter-terminated.
 *
 * Return: NULL pointer-terminated array of
 * pointers to tokens in read line from stdin
 */
char **stdin_tokens(void)
{
	/* for reading the stdin line */
	size_t buffsize = 100;
	char *stdin_line = NULL;

	/* for getting the off the stdin line tokens */
	char **result;
	char *token;
	int line_len;
	int result_index = 0;

	getline(&stdin_line, &buffsize, stdin);
	line_len = strlen(stdin_line);

	result = malloc(sizeof(char *) * (line_len + 1));

	token = strtok(stdin_line, " \n");
	while (token)
	{
		result[result_index] = token;
		result_index++;
		token = strtok(NULL, " \n");
	}
	result[result_index] = NULL;

	return (result);
}

