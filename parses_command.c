#include "shell.h"

/**
 * err_av - to assist me in utilizing function lines
 * @av: pointer to pointer to chars
 * Return: ointer / NULL if error
 */
char **err_av(char **av)
{
	if (av == NULL)
	{
		perror("./hsh: allocation error\n");
		return (NULL);
	}
	return (av);
}

/**
 * _parses_command - parses commands
 * @inp_command: input commands
 * Return: pointer to a pointer of chars
 * / NULL on error
 */
char **_parses_command(char *inp_command)
{
	char **av, *token;
	char *delim = " \t\r\n\a";
	int i = 0, av_s = 64;

	av = malloc(sizeof(char *) * av_s);
	if (err_av(av) == NULL)
		return (NULL);
	token = strtok(inp_command, delim);
	while (token != NULL)
	{
		av[i] = token;
		i++;
		if (i >= av_s)
		{
			av_s += 64;
			av = _realloc(av, (av_s - 64), av_s * sizeof(char *));
			if (err_av(av) == NULL)
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	return (av);
}
