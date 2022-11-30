#include "main.h"

/**
 * main - Runs shell.
 *
 * Return: (hopefully) 0
 */
int main(void)
{
	int status = 1;

	while (status == 1)
	{
		char **line_tokens;

		printf("$ ");

		line_tokens = stdin_tokens();

		status = create_fork(line_tokens);

		free(*line_tokens);
		free(line_tokens);
	}
	return (0);
}

