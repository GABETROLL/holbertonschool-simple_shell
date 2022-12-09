#include "main.h"

/**
 * special_cases - Handles program token being "exit"
 * or "env".
 *
 * @tokens: tokens from stdin in this program
 * @shell_name: name of the executable of this program
 * @env: shell environment of this program
 *
 * Return: 0 if the shell should exit,
 * 1 if the shell should continue,
 * 2 if neither
 */
int special_cases(char **tokens, char *shell_name, char **env)
{
	if (tokens[0])
	{
		if (_strcmp(tokens[0], "exit") == 0)
		{
			if (!tokens[1])
				return (0);

			write(1, shell_name, _strlen(shell_name));
			write(1, ": sh: 1: exit: Illegal number: ", 31);
			write(1, tokens[1], _strlen(tokens[1]));
			write(1, "\n", 1);

			return (1);
		}
		if (_strcmp(tokens[0], "env") == 0)
		{
			int i = 0;
			int str_len = 0;

			while (env[i])
			{
				str_len = _strlen(env[i]);
				write(1, env[i], str_len);
				write(1, "\n", 1);
				i++;
			}
			return (1);
		}
	}
	return (2);
}
