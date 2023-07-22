#include "shell.h"

int (*builtin_func[])(char **, char *) = {
	&_cd,
	&_exit_,
	&_env,
	&_setenv,
	&_unsetenv
};
/**
 * _p_command - Verifies whether the input command
 * is a built-in command and executes it; otherwise
 * invokes the execute_cmd function.
 * @command: command passed into the main loop of the shell
 * @inp_command: command to be freed
 * @loop_count: for error msg
 * @p_name: for error msg
 * Return: 0 on success and -1 on error
 */
int _p_command(char **command, char *inp_command, char *p_name, int loop_count)
{
	char *builtin_command[] = {"cd", "exit", "env", "setenv", "unsetenv"};
	int funct_len, i;

	if (command[0] == NULL)
		return (1);
	funct_len = sizeof(builtin_command) / sizeof(char *);
	for (i = 0; i < funct_len; i++)
	{
		if (strcmp(command[0], builtin_command[i]) == 0)
			return ((*builtin_func[i])(command, inp_command));
	}
	return (execute_command(command, p_name, loop_count));

}

/**
 * execute_command - executes non built-ins commands
 * @command: command to be executed
 * @p_name: for error msg
 * @loop_count: for error msg
 * Return: an int / on error -1
 */
int execute_command(char **command, char *p_name, int loop_count)
{
	pid_t child_pid;
	int status, check_free = 0;
	struct stat st_nd;

	command = c_command(command, p_name, loop_count, &check_free);
	if (command == NULL)
		return (1);

	if (stat(command[0], &st_nd) == 0)
	{
		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Error:");
			return (-1);
		}
		else if (child_pid == 0)
		{
			if (execve(command[0], command, environ) == -1)
			{
				dprintf(1, "%s: %d: ", p_name, loop_count);
				perror("execve");
				if (check_free == 1)
					free(command[0]);
				return (-1);
			}
		}
		else
		{
			do {
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	if (check_free == 1)
		free(command[0]);
	return (1);
}
