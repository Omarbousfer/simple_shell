#include "shell.h"

/**
 * _setenv - changes or adds an environment variable
 * @command: array
 * @input: input
 * Return: 0 on success / 1 on failure
 */
int _setenv(char **command, char *input)
{
	char *name, *value;

	(void)input;

	name = command[1];
	value = command[2];

	if (name == NULL || value == NULL)
	{
		fprintf(stderr, "Usage: setenv <name> <value>\n");
	}
	if (setenv(name, value, 1) != 0)
	{
		fprintf(stderr, "Failed to set environment variable\n");
	}
	return (1);
}

/**
 * _unsetenv - deletes the variable
 * name from the environment
 * @command: array
 * @input: input
 * Return: 0 on success / 1 on failure
 */
int _unsetenv(char **command, char *input)
{
	char *name;

	(void)input;

	name = command[1];

	if (name == NULL)
	{
		fprintf(stderr, "Usage: unsetenv <name>\n");
	}
	if (unsetenv(name) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	}
	return (1);
}
