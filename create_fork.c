#include "main.h"

int create_fork(char *shell_name, char **tokens, char **env, int is_terminal)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (0);
	}
	else if (child_pid == 0)
	{
		char *full_file_name;
		char *path;

		if (!tokens || !tokens[0])
			return (0);

		execve(tokens[0], tokens, env);

		/*
		 * Everything past the above line is
		 * due to an executable not being found.
		 *
		 * if the stdin wasn't empty:
		 */

		path = get_path(env);
		full_file_name = split_path(tokens[0], path);

		if (full_file_name != NULL && path != NULL)
		{
			char *exec_name = tokens[0];

			tokens[0] = full_file_name;
			execve(tokens[0], tokens, env);
			tokens[0] = exec_name;
			free(full_file_name);
		}

		if (tokens != NULL && *tokens != NULL)
		{
			write(1, shell_name, _strlen(shell_name));

			if (is_terminal)
				write(1, ": No such file or directory\n", 28);
			else
			{
				write(1, ": 1: ", 5);
				write(1, tokens[0], _strlen(tokens[0]));
				write(1, ": not found\n", 12);
			}
		}

		return (0);
	}
	else
	{
		wait(&status);
	}
	return (1);
}

