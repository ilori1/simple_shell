#include "shell.h"

/**
* **strtow - it splits a string into words. Repeat delim are ignored
* @str: it the input str
* @d: of the delim str
* Return: of a pointer to an array of strs, or NULL on failure
*/

char **strtow(char *str, char *d)
{
int p, o, v, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (p = 0; str[p] != '\0'; p++)
if (!is_delim(str[p], d) && (is_delim(str[p + 1], d) || !str[p + 1]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numwords)*sizeof(char *));
if (!s)
return (NULL);
for (p = 0, o = 0; o < numwords; o++)
{
while (is_delim(str[p], d))
p++;
v = 0;
while (!is_delim(str[p + v], d) && str[p + v])
v++;
s[o] = malloc((v + 1) * sizeof(char));
if (!s[o])
{
for (v = 0; v < o; v++)
free(s[v]);
free(s);
return (NULL);
}
for (m = 0; m < v; m++)
s[o][m] = str[p++];
s[o][m] = 0;
}
s[o] = NULL;
return (s);
}

/**
* **strtow2 - it splits a str into words
* @str: of the input str
* @d: of the delim
* Return: of a pointer to an array of strs, or NULL on failure
*/
char **strtow2(char *str, char d)
{
int p, j, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (p = 0; str[p] != '\0'; p++)
if ((str[p] != d && str[p + 1] == d) ||
(str[p] != d && !str[p + 1]) || str[p + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords)*sizeof(char *));
if (!s)
return (NULL);
for (p = 0, j = 0; j < numwords; j++)
{
while (str[p] == d && str[p] != d)
p++;
k = 0;
while (str[p + k] != d && str[p + k] && str[p + k] != d)
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[p++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}
