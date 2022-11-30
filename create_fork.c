#include "main.h"

int create_fork(char **tokens)
{
	pid_t child_pid;
	pid_t test;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}
	else if (child_pid == 0)
	{
		execve(tokens[0], tokens, NULL);
		test = getpid();
		printf("%u\n", test);
	}
	else
	{
		wait(&status);
	}
	return (1);
}

