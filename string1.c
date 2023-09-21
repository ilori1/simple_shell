#include "shell.h"

/**
* _strcpy - it copies a str
* @dest: of the destination
* @src: of the source
*
* Return: the pointer to destination
*/
char *_strcpy(char *dest, char *src)
{
int k = 0;

if (dest == src || src == 0)
return (dest);
while (src[k])
{
dest[k] = src[k];
k++;
}
dest[k] = 0;
return (dest);
}

/**
* _strdup - it duplicates a str
* @str: of the str to duplicate
*
* Return: the pointer to the duplicated str
*/
char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
* _puts - it prints an input str
* @str: str to be printed
*
* Return: Nothing (0)
*/
void _puts(char *str)
{
int p = 0;

if (!str)
return;
while (str[p] != '\0')
{
_putchar(str[p]);
p++;
}
}

/**
* _putchar - it writes the char c to stdout
* @c: char to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
static int p;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || p >= WRITE_BUF_SIZE)
{
write(1, buf, p);
p = 0;
}
if (c != BUF_FLUSH)
buf[p++] = c;
return (1);
}
