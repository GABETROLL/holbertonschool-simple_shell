#include "main.h"

/**
 * main - Runs shell.
 *
 * Return: (hopefully) 0
 */
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	int status = 1;

	/* to get line from stdin: */
	size_t buffsize;
	char *stdin_line;

	while (status)
	{
		char **line_tokens = NULL;
		int is_terminal;
		int special_case;

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

		special_case = special_cases(line_tokens, argv[0], env);

		/* exit */
		if (special_case == 0)
		{
			free(stdin_line);
			free(line_tokens);
			return (0);
		}
		/* env */
		else if (special_case == 1)
		{
			free(stdin_line);
			free(line_tokens);
			continue;
		}

		status = create_fork(argv[0], line_tokens, env, is_terminal);

		free(stdin_line);
		free(line_tokens);
	}

	return (0);
}

