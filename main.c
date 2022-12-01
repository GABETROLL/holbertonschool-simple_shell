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
	size_t buffsize;
	char *stdin_line;

	while (status)
	{
		char **line_tokens = NULL;

		buffsize = 100;
		stdin_line = NULL;

		if (isatty(0))
			printf("$ ");

		if (getline(&stdin_line, &buffsize, stdin) == -1)
			break;

		line_tokens = str_tokens(stdin_line);
		if (!line_tokens)
		{
			free(stdin_line);
			break;
		}

		status = create_fork(line_tokens);

		free(stdin_line);
		free(line_tokens);
	}

	return (0);
}

