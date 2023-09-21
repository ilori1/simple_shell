#include "shell.h"

/**
 * bfree - Frees  pointer and sets its address to NULL.
 * @ptr: Address of  pointer to free.
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
