#include "shell.h"

/**
<<<<<<< HEAD
 * is_chain - test if current char in buffer is  chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks we shall continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces an aliases in tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
=======
* is_chain - the test if current char in buffer is a chain delim
* @info: parameter struct
* @buf: of the char buffer
* @p: the ad of current position in buf
*
* Return: 1 if chain delim, 0 otherwise
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t h = *p;

if (buf[h] == '|' && buf[h + 1] == '|')
{
buf[h] = 0;
h++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[h] == '&' && buf[h + 1] == '&')
{
buf[h] = 0;
h++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[h] == ';') /* found end of this command */
{
buf[h] = 0; /* replace semicolon with null */
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = h;
return (1);
}

/**
* check_chain - it checks we should continue chaining based on last stat
* @info: parameter struct
* @buf: of the char buffer
* @p: the ad of current position in buf
* @i: the starting position in buf
* @len: length of buffer
*
* Return: the Void
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t k = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
k = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
k = len;
}
}

*p = k;
}

/**
* replace_alias - it replaces an aliases in the tokenized str
* @info:  parameter struct
*
* Return: is 1 if replaced, 0 otherwise
*/
int replace_alias(info_t *info)
{
int k;
list_t *node;
char *p;

for (k = 0; k < 10; k++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}

/**
* replace_vars - it replaces vars in the tokenized str
* @info: parameter struct
*
* Return: is 1 if replaced, 0 otherwise
*/
int replace_vars(info_t *info)
{
int k = 0;
list_t *node;

for (k = 0; info->argv[k]; k++)
{
if (info->argv[k][0] != '$' || !info->argv[k][1])
continue;

if (!_strcmp(info->argv[k], "$?"))
{
replace_string(&(info->argv[k]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[k], "$$"))
{
replace_string(&(info->argv[k]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[k][1], '=');
if (node)
{
replace_string(&(info->argv[k]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[k], _strdup(""));

}
return (0);
}

/**
* replace_string - it replaces str
* @old: an ad of old str
* @new: the new str
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
>>>>>>> 25379caf809844f06b4d2077ab42251989170a2f
}
