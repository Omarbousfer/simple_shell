#include "shell.h"

/**
 * check_alloc_error - checks memory allocation if it's successfull or not
 * @string: string to check its returned value
 * Return: expected output
 */
char *check_alloc_error(char *string)
{
	if (string == NULL)
	{
		free(string);
		return (NULL);
	}
	return (string);
}

/**
 * _getline - Replace getline function
 * @line_pointer: buffer used to hold line to read from
 * the stream
 * @buffer_size: the maximum number of input that can be read
 * if n is to small more space is reallocated
 * @stream: file stream from which reading takes place from
 * Return: returns a ssize_t value of no. of characters read
 */
ssize_t _getline(char **line_pointer, size_t *buffer_size, FILE *stream)
{
	int x;
	size_t new_buffer_size, i = 0;

	if ((*line_pointer) == NULL)
	{
		if ((*buffer_size) <= 0)
			*buffer_size = BUFFER_SIZE;
		(*line_pointer) = malloc(sizeof(char) * (*buffer_size));
		if (check_alloc_error(*line_pointer) == NULL)
			return (-1);
	}
	while (1)
	{
		fflush(stdout);
		x = sh_getchar(stream);
		if (x == '\n' || x == EOF)
		{
			(*line_pointer)[i] = '\0';
			if (x == EOF)
			{
				return (-1);
			}
			else
			{
				return (i + 1);
			}

		}
		(*line_pointer)[i] = x;
		i++;
		if (i >= (*buffer_size))
		{
			new_buffer_size = (*buffer_size) + 3;
			(*line_pointer) = _realloc((*line_pointer), (*buffer_size), new_buffer_size);
			if (check_alloc_error((*line_pointer)) == NULL)
				return (-1);
			(*buffer_size) = new_buffer_size;
		}
	}
	return (i);
}

/**
 * sh_getchar - reads the next character from the stream
 * and returns it as an unsigned character cast to an int,
 * or EOF or error
 * @stream: input to read characters from
 * Return: char read casted to an int, or EOF on end of file
 */
int sh_getchar(FILE *stream)
{
	char char_buffer[1];
	char *char_r;
	int status;

	status = read(fileno(stream), char_buffer, 1);
	if (status > 0)
	{
		char_r = char_buffer;
		return (*char_r);
	}
	if (status == -1)
		return (0);
	return (EOF);
}
