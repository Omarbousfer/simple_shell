#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE (size_t)128
#define MAX_PATH_LENGTH 64

extern char **environ;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>

char *_strtok(char *str, const char *delim);
ssize_t _getline(char **linepointer, size_t *n, FILE *stream);
void *_realloc(void *pointer, size_t o_size, size_t n_size);
int sh_getchar(FILE *stream);
int execute_command(char **command, char *p_name, int loop_count);
char **_parses_command(char *inp_command);
int _p_command(char **command, char *inp, char *p_name, int loop_count);
char **c_command(char **command, char *program_name, int loop_count, int *flag);
char **get_path_tokens(char *path, char *copy_path);
int _putchar(char c);
int _cd(char **command, char *input);
int _exit_(char **command, char *input);
int _env(char **command, char *input);
int _setenv(char **command, char *input);
int _unsetenv(char **command, char *input);
char *get_environement(const char *environement_name);

#endif
