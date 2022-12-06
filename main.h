#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char **str_tokens(char *str);
int create_fork(char **tokens, char *stdin_line, char **env);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int compare(char **tokens, char **env);
char *_strcpy(char *dest, char *src);

#endif
