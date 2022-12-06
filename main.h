#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char **str_tokens(char *str);
int create_fork(char *shell_name, char **tokens, int is_terminal);
int special_cases(char **tokens, char *shell_name, char **env);
int _strlen(char *s);
int _strcmp(char *a, char *b);
#endif
