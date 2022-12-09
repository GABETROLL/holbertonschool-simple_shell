#include "main.h"

/**
 * get_path - get PATH string in the env
 * @env: environment list with variables
 * Return: pointer to string with all directories
 * in 'PATH' string
 */
char *get_path(char **env)
{
	int i;
	char *path = NULL;

	if (!env)
		return (NULL);

	for (i = 0; env[i]; i++)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i];
			break;
		}
	}

	if (path == NULL)
		return (NULL);

	path = strtok(path, "=");

	if (path)
		path = strtok(NULL, "=");

	return (path);
}

/**
 * split_path - Get the full path to the file naned
 * 'file_token' if it's in PATH, NULL otherwise
 *
 * THE RETURNED STRING MUST BE FREED!!!!
 *
 * @file_token: name of executable to find in path
 * @path: string containing all directories in PATH
 *
 * Return: full path to file 'file_token' if found
 * in PATH, NULL otherwise
 */
char *split_path(char *file_token, char *path)
{
	struct stat st;
	char *dir;

	if (path == NULL)
		return (NULL);

	dir = strtok(path, ":");

	while (dir)
	{
		int dir_len = _strlen(dir);
		int file_token_len = _strlen(file_token);

		/* 1 char for slash, 1 char for terminating null byte */
		char *full_file_name = malloc(sizeof(char) * (dir_len + 2 + file_token_len));

		if (!full_file_name)
			return (NULL);

		_strcpy(full_file_name, dir);
		_strcat(full_file_name, "/");
		_strcat(full_file_name, file_token);

		if (stat(full_file_name, &st) == 0)
			return (full_file_name);

		dir = strtok(NULL, ":");
		free(full_file_name);
	}

	return (NULL);
}

