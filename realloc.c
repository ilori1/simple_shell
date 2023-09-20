#include "shell.h"

/**
* _memset - it fills memory with a const byte
* @s: of the pointer to the memory area
* @b: of the byte to fill *s with
* @n: of the amount of bytes to be filled
* Return: the (s) a pointer to the memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int p;

for (p = 0; p < n; p++)
s[p] = b;
return (s);
}

/**
* ffree - the frees a str of strs
* @pp: the str of strs
*/
void ffree(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
* _realloc - it reallocates a block of memory
* @ptr: of the pointer to previous malloc'ated block
* @old_size: the byte size of previous block
* @new_size: the byte size of new block
*
* Return: the pointer to the ol'block name.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
