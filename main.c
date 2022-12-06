#include "main.h"

/**
 * main - Runs shell.
 *
 * Return: (hopefully) 0
 */
int main(int ac, char **av, char **env)
{
	int status = 1;

	/* to get line from stdin: */
	size_t buffsize;
	char *stdin_line;
	
	(void) ac;
	(void) av;
	
	while (status)
	{
		char **line_tokens = NULL;

		buffsize = 0;
		stdin_line = NULL;

		if (isatty(0))
			write(1, "$ ", 2);

		if (getline(&stdin_line, &buffsize, stdin) == EOF)
		{
			free(stdin_line);
			exit (EXIT_SUCCESS);
		}

		line_tokens = str_tokens(stdin_line);
		if (!line_tokens)
		{
			free(stdin_line);
			break;
		}
		
		/* check if stdin is exit or env */
		if (compare(line_tokens, env) == 1)
                {
                        free(stdin_line);
			free(line_tokens);
			break;
                }
		status = create_fork(line_tokens, stdin_line, env);
		free(stdin_line);
		free(line_tokens);

	}

	return (0);
}

