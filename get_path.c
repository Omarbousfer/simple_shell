#include "shell.h"

/**
 * get_path_tokens - Retrieves the array containing the path
 * directories of the environ variable
 * @path: original path
 * @copy_path: copy path
 * Return: an array of all path_directories
 */
char **get_path_tokens(char *path, char *copy_path)
{
	char **path_of_tokens, *token;
	int len = 128, x = 0;

	path_of_tokens = malloc(sizeof(char *) * len);
	if (!path_of_tokens)
	{
		perror("./hsh: allocation error\n");
		return (NULL);
	}
	strcpy(copy_path, path);
	token = strtok(copy_path, ":\r\n\a");
	while (token != NULL)
	{
		path_of_tokens[x] = token;
		x++;
		if (x >= len)
		{
			len += 128;
			path_of_tokens = _realloc(path_of_tokens, len - 128, len * sizeof(char *));
			if (!path_of_tokens)
			{
				perror("./hsh: allocation error\n");
				return (NULL);
			}
		}
		token = strtok(NULL, ":\r\n\a");
	}
	path_of_tokens[x] = NULL;
	return (path_of_tokens);
}
