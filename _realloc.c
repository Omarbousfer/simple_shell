#include "shell.h"

/**
 * _realloc - replace built-in realloc function
 * @pointer: Pointer used for reallocating memory
 * @o_size: size of init allocated memory
 * @n_size: size of new memory
 * Return: On success a pointer
 * / NULL pointer on error
 */
void *_realloc(void *pointer, size_t o_size, size_t n_size)
{
	void *new_pointer;
	char *pointer_cp, *fil_n_pointer;
	size_t i;


	if (o_size == n_size)
		return (pointer);
	if (pointer == NULL)
	{
		new_pointer = malloc(n_size);
		if (new_pointer == NULL)
			return (NULL);
		return (new_pointer);
	}
	if (n_size == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}
	pointer_cp = pointer;
	new_pointer = malloc(sizeof((*pointer_cp)) * n_size);
	if (new_pointer == NULL)
	{
		free(pointer);
		return (NULL);
	}
	fil_n_pointer = new_pointer;
	for (i = 0; i < o_size && i < n_size; i++)
		fil_n_pointer[i] = pointer_cp[i];
	free(pointer);
	return (new_pointer);
}
