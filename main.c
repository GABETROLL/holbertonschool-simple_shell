#include "main.h"

/**
 * main - Runs shell.
 *
 * Return: (hopefully) 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	int status = 1;

	/* to get line from stdin: */
	size_t buffsize;
	char *stdin_line;

	while (status)
	{
		char **line_tokens = NULL;
		int is_terminal;

		buffsize = 100;
		stdin_line = NULL;

		is_terminal = isatty(0);
		if (is_terminal)
			write(1, "$ ", 2);

		if (getline(&stdin_line, &buffsize, stdin) == -1)
		{
			free(stdin_line);
			break;
		}

		line_tokens = str_tokens(stdin_line);
		if (!line_tokens)
		{
			free(stdin_line);
			break;
		}

		if (line_tokens[0] && equal_strings(line_tokens[0], "exit") && !line_tokens[1])
		{
			free(stdin_line);
			free(line_tokens);
			return (0);
		}

		status = create_fork(argv[0], line_tokens, is_terminal);

		free(stdin_line);
		free(line_tokens);
	}

	return (0);
}

