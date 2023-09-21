#include "shell.h"

/**
<<<<<<< HEAD
 * **strtow - splits  string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to  array of strings, or NULL on failure
 */

char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
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
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
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
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
=======
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
s[k] = malloc((k + 1) * sizeof(char));
if (!s[g])
{
for (k = 0; k < g; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[k][m] = str[r++];
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
>>>>>>> 25379caf809844f06b4d2077ab42251989170a2f
}
