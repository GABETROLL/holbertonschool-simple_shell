#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	size_t buffsize = 200;
	ssize_t user_input;
	char *buffer = malloc(sizeof(char) * buffsize);

	while (1)
	{
		printf("$ ");
		user_input = getline(&buffer, &buffsize, stdin);

		printf("%s", buffer);
	}
	return (0);
}

