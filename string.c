#include "shell.h"

/**
* _strlen - it returns the length of a str
* @s: strs whose length to check
*
* Return: the int length of str
*/
int _strlen(char *s)
{
int j = 0;

if (!s)
return (0);

while (*s++)
j++;
return (j);
}

/**
* _strcmp - it performs lexicogarphic comparison of two strs.
* @s1: of the first string
* @s2: of the second string
*
* Return: be -ve if s1 < s2,& +ve if s1 > s2, zero if s1 == s2
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - it checks if needle starts with haystack
* @haystack: the string to search
* @needle: substring to find
*
* Return: an ad of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* _strcat - will concatenates two strs
* @dest: of the destination buffer
* @src: of the source buffer
*
* Return: the pointer to destination buffer
*/
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
