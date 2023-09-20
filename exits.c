#include "shell.h"

/**
**_strncpy - It copies a str
*@dest: a destination str to be copied to
*@src: the sources str
*@n: the amounts of char to be copied
*Return: the concatenated str
*/
char *_strncpy(char *dest, char *src, int n)
{
int c, v;
char *s = dest;

c = 0;
while (src[c] != '\0' && c < n - 1)
{
dest[c] = src[c];
c++;
}
if (c < n)
{
v = c;
while (v < n)
{
dest[v] = '\0';
v++;
}
}
return (s);
}

/**
**_strncat - It concatenates two strs
*@dest:  first strs
*@src: second strs
*@n:  amounts of bytes to be maximally used
*Return: the concatenated str
*/
char *_strncat(char *dest, char *src, int n)
{
int c, v;
char *s = dest;

c = 0;
v = 0;
while (dest[c] != '\0')
c++;
while (src[v] != '\0' && v < n)
{
dest[c] = src[v];
c++;
v++;
}
if (v < n)
dest[c] = '\0';
return (s);
}

/**
**_strchr - it locates a char in a str
*@s: strs to be parsed
*@c: char to look for
*Return: (s) a pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}
