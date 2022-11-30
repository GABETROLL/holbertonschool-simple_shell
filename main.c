#include "main.h"

/**
 * main - Runs shell.
 *
 * Return: (hopefully) 0
 */
int main(void)
{
	int status = 1;

	/* to get line from stdin: */
	char *stdin_line = NULL;
	char **line_tokens = NULL;

	while (status == 1)
	{
		size_t buffsize = 100;

		stdin_line = NULL;
		line_tokens = NULL;

		printf("$ ");

		getline(&stdin_line, &buffsize, stdin);
		if (!stdin_line)
			continue;

		line_tokens = str_tokens(stdin_line);
		if (!line_tokens)
		{
			free(stdin_line);
			continue;
		}

		status = create_fork(line_tokens);

		free(line_tokens);
		free(stdin_line);
	}

	free(line_tokens);
	free(stdin_line);

	return (0);
}

