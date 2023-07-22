#include "shell.h"

/**
 * check_alloc_errors - helps in minimizing 
 * the number of program lines
 * @new_command: input to handle
 * Return: -1 if it's error
 */
int check_alloc_errors(char *new_command)
{
	if (!new_command)
	{
		perror("./hsh: allocation error\n");
		return (-1);
	}
	return (0);
}

/**
 * check_alloc_err - helps in minimizing the number
 * of function lines
 * @new_command: address
 * @buffer: inp to be checked
 * Return: -1 if it's error
 */
int check_alloc_err(char *buffer, char *new_command)
{
	if (!buffer)
	{
		free(new_command);
		perror("./hsh: allocation error\n");
		return (-1);
	}
	return (0);
}
/**
 * free_alloc1 - frees up alloc memory
 * @memory1: to be freed
 * @memory2: to be freed
 * Return: ntg
 */
void free_alloc1(char *memory1, char **memory2)
{
	free(memory1);
	free(memory2);
}
/**
 * free_alloc2 - minimize function lines
 * @memory1: to be freed
 * @memory2: to be freed
 * @memory3: to be freed
 * Return: ntg
 */
void free_alloc2(char *memory1, char **memory2, char *memory3)
{
	free(memory1);
	free(memory2);
	free(memory3);
}
/**
 *c_command - to process the inp command
 * @command: array of inp
 * @program_name: for error messages
 * @loop_count: for error message
 * @flag: check if mem was succefully allocated
 * Return: an array of processed input command / NULL on failure
 */
char **c_command(char **command, char *program_name, int loop_count, int *flag)
{
	char *new_command, **path_of_tokens, *path, *copy_path;
	int i, j;

	for (i = 0; *(command[0] + i) != '\0'; i++)
	{
		if (*(command[0] + i) == '/')
			return (command);
	}
	new_command = malloc(sizeof(char) * MAX_PATH_LENGTH);
	if (check_alloc_errors(new_command) == -1)
		return (NULL);
	path = get_environement("PATH");
	copy_path = malloc(sizeof(char) * (strlen(path) + 1));
	if (check_alloc_err(copy_path, new_command) == -1)
		return (NULL);
	path_of_tokens = get_path_tokens(path, copy_path);
	if (path_of_tokens == NULL)
	{
		free(copy_path);
		return (NULL);
	}
	for (j = 0; path_of_tokens[j] != NULL; j++)
	{
		strcpy(new_command, path_of_tokens[j]);
		if (*new_command != '\0')
			strcat(new_command, "/");
		else
			strcat(new_command, "./");
		strcat(new_command, command[0]);
		if (access(new_command, X_OK) != -1)
		{
			command[0] = new_command;
			*flag = 1;
			free_alloc1(copy_path, path_of_tokens);
			return (command);
		}
	}
	free_alloc2(new_command, path_of_tokens, copy_path);
	dprintf(2, "%s: %d: not found\n", program_name, loop_count);
	return (NULL);
}
