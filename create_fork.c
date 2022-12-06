#include "main.h"

int create_fork(char **tokens)
{
	pid_t child_pid;
	int status;

	(void) stdin_line;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (0);
	}
	else if (child_pid == 0)
	{
		execve(tokens[0], tokens, NULL);

		/*
		 * Everything past the above line is
		 * due to an executable not being found.
		 *
		 * if the stdin wasn't empty:
		 */

		if (tokens != NULL && *tokens !=  NULL)
			write(1, "No such file or directory\n", 26);

		return (0);
	}
	else
	{
		wait(&status);
	}
	return (1);
}

