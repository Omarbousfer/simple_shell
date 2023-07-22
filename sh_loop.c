#include "shell.h"

/**
 * g_err - to manage lines
 * @n_of_chars: number of chars
 * @input_command: command to be freed
 * Return: 0 on success / -1 on errors
 */
int g_err(ssize_t n_of_chars, char *input_command)
{
	if (n_of_chars == -1)
	{
		free(input_command);
		return (-1);
	}
	return (0);
}
/**
 * handle_sig - used to handle signal
 * @signal: signal
 * Return: ntg
 */
void handle_sig(int signal)
{
	(void)signal;
	_putchar('\n');
	printf("$ ");
	fflush(stdout);

}
/**
 * main - main function of shell
 * @ac: arguments count
 * @av: arguments values
 * Return: 0 on success / -1 on errors
 */
int main(int ac, char **av)
{
	char **command_argmnt;
	char *input_command = NULL;
	ssize_t n_char;
	size_t len = 0;
	int loop_count = 1, status = 1;

	(void)ac;
	signal(SIGINT, handle_sig);
	while (status == 1)
	{
		fflush(stdout);
		if (isatty(STDIN_FILENO) != 0)
			printf("$ ");
		n_char = _getline(&input_command, &len, stdin);
		if (g_err(n_char, input_command) == -1)
			return (0);
		command_argmnt = _parses_command(input_command);
		if (command_argmnt == NULL)
		{
			free(input_command);
			return (0);
		}
		status = _p_command(command_argmnt, input_command, av[0], loop_count);
		free(command_argmnt);
		loop_count += 1;
	}
	free(input_command);
	return (0);
}
