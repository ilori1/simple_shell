#include "shell.h"

/**
* _eputs - printing an input string
* @str: strings to be printed
*
* Return: Nothing
*/
void _eputs(char *str)
{
int g = 0;

if (!str)
return;
while (str[g] != '\0')
{
_eputchar(str[g]);
g++;
}
}

/**
* _eputchar - writing the character c to stderr
* @c: characters to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _eputchar(char c)
{
static int u;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || u >= WRITE_BUF_SIZE)
{
write(2, buf, u);
u = 0;
}
if (c != BUF_FLUSH)
buf[u++] = c;
return (1);
}

/**
* _putfd - writing the character c to given fd
* @c: characters to print
* @fd: The filedescri to write to
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putfd(char c, int fd)
{
static int o;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || o >= WRITE_BUF_SIZE)
{
write(fd, buf, o);
o = 0;
}
if (c != BUF_FLUSH)
buf[o++] = c;
return (1);
}

/**
* _putsfd - printing an input str
* @str:  strings to be printed
* @fd: the filedescriptor to write to
*
* Return: numbers of chars put
*/
int _putsfd(char *str, int fd)
{
int n = 0;

if (!str)
return (0);
while (*str)
{
n += _putfd(*str++, fd);
}
return (n);
}
