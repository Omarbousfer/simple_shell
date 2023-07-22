#include "shell.h"
/**
 * _strtok - splits a string and returns an array
 * of each word of the string
 * @str: string
 * @delim: delimiter
 * Return: pointer to the token
 */
char *_strtok(char *str, const char *delim)
{
	static char *buffer;
	char *ts;
	int tn;

	if (str != NULL)
		buffer = str;

	if (buffer == NULL || *buffer == '\0')
		return (NULL);

	ts = buffer;

	tn = strcspn(buffer, delim);
	buffer += tn;

	if (*buffer != '\0')
	{
		*buffer = '\0';
		buffer++;
	}

	if (*ts == '\0')
	{
		return (_strtok(NULL, delim));
	}

	return (ts);
}
