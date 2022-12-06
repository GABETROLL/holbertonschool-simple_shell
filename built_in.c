#include "main.h"


int compare(char **tokens, char **env)
{
	int i, str_len;

	for (i = 0; tokens[i]; i++)
	{
		if (_strcmp(tokens[i], "exit") == 0)
			return (1);
		if (_strcmp(tokens[i], "env") == 0)
		{
			while (env[i])
			{
				str_len = _strlen(env[i]);
				write(1, env[i], str_len);
				write(1, "\n", 1);
				i++;
			}
			return (0);
		}
	}
	return (0);
}
