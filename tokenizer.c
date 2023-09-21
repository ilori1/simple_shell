#include "shell.h"

/**
* **strtow - it splits a str into words. Repeat delim are ignored
* @str: of the input str
* @d: of the delim str
* Return: a pointer to an array of str, or NULL on failure
*/

char **strtow(char *str, char *d)
{
int r, g, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (r = 0; str[r] != '\0'; r++)
if (!is_delim(str[r], d) && (is_delim(str[r + 1], d) || !str[r + 1]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numwords)*sizeof(char *));
if (!s)
return (NULL);
for (r = 0, g = 0; g < numwords; g++)
{
while (is_delim(str[r], d))
r++;
k = 0;
while (!is_delim(str[r + k], d) && str[r + k])
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[g])
{
for (k = 0; k < g; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[r++];
s[g][m] = 0;
}
s[g] = NULL;
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
int i, j, v, x, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords)*sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (str[i] == d && str[i] != d)
i++;
v = 0;
while (str[i + v] != d && str[i + v] && str[i + v] != d)
v++;
s[j] = malloc((v + 1) * sizeof(char));
if (!s[j])
{
for (v = 0; v < j; v++)
free(s[v]);
free(s);
return (NULL);
}
for (x = 0; x < v; x++)
s[j][x] = str[i++];
s[j][x] = 0;
}
s[j] = NULL;
return (s);
}
