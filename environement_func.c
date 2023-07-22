#include "shell.h"

/**
 * get_environement - looks for the environment list
 * to look up for the environment variable environement_name
 * @environement_name: name of the environement
 * Return: pointer to environement
 * / NULL in the absence of a match
 */
char *get_environement(const char *environement_name)
{
	size_t len;
	char **env = environ;

	len = strlen(environement_name);
	while (*env != NULL)
	{
		if ((strncmp(*env, environement_name, len)) == 0 && (*env)[len] == '=')
		{
			return (&((*env)[len + 1]));
		}
		env++;
	}
	return (NULL);
}
