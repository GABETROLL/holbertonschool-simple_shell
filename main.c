#include "main.h"

int main(void)
{
	size_t buffsize = 0;
	char *buffer = NULL, *token;
	char **tokens = malloc(sizeof(char *));
	int i = 0;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &buffsize, stdin);
		token = strtok(buffer, " \n");
		
		/** divide string and asign to tokens */
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = strtok(NULL, " \n");
		}
		create_fork(tokens);
	}
	return (0);
}

