#include "shell.h"

/**
 * _cd - changes the working directory
 * @command: specified directory
 * @input: void
 * Return: 0 on success / -1 on error
 */
int _cd(char **command, char *input)
{
	(void)input;
	if (command[1] == NULL)
	{
		if (chdir(get_environement("HOME")) != 0)
			perror("chdir");
	}
	else
	{
		if (chdir(command[1]) != 0)
		{
			perror("chdir");
		}
	}
	return (1);
}

/**
 * c_exit_value - checks if exit value only have numbers
 * @exit_string: input exit value
 * Return: 0 on success / -1 on failure
 */
int c_exit_value(char *exit_string)
{
	int i;

	i = 0;
	while (exit_string[i] != '\0')
	{
		if (isdigit(exit_string[i]))
			i++;
		else
			return (-1);
	}
	return (1);
}

/**
 * _exit - similar to exit func
 * @command: array
 * @input: input
 * Return: exit or 0
 */
int _exit_(char **command, char *input)
{
	int exit_value = 0;

	if (command[1] == NULL)
	{
		free(command);
		free(input);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (c_exit_value(command[1]) == 1)
		{
			exit_value = atoi(command[1]);
			if (exit_value >= 256)
			{
				free(command);
				free(input);
				exit(exit_value - 256);
			}
			if (exit_value < 0)
				return (0);
			free(command);
			free(input);
			exit(exit_value);
		}
		else
			dprintf(2, "Illegal number: %s\n", command[1]);
	}
	return (1);

}
/**
 * _env - similar to env func
 * @command: array
 * @input: input
 * Return: 0 on success
 */
int _env(char **command, char *input)
{
	int i;

	(void)input, (void)command;
	for (i = 0; environ[i] != NULL; i++)
	{
		dprintf(STDOUT_FILENO, "%s\n", environ[i]);
	}
	return (1);
}
