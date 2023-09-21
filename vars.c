#include "shell.h"

/**
* is_chain - it test if current char in buf is a chain delim
* @info: of the parameter struct
* @buf: of the char buffer
* @p: the ad of current position in buf
*
* Return: 1 if chain delimeter, 0 otherwise
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t u = *p;

if (buf[u] == '|' && buf[u + 1] == '|')
{
buf[u] = 0;
u++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[u] == '&' && buf[u + 1] == '&')
{
buf[u] = 0;
u++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[u] == ';') /* found end of this command */
{
buf[u] = 0; /* replace semicolon with null */
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = u;
return (1);
}

/**
* check_chain - it checks we should continue chaining based on last stat
* @info: of the parameter struct
* @buf: of the char buffer
* @p: the ad of current position in buf
* @i: starting position in buf
* @len: the length of buf
*
* Return: the Void
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t u = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
u = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
u = len;
}
}

*p = u;
}

/**
* replace_alias - it replaces an aliases in the tokenized string
* @info: of the parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_alias(info_t *info)
{
int u;
list_t *node;
char *p;

for (u = 0; u < 10; u++)
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
* @info: of the parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_vars(info_t *info)
{
int p = 0;
list_t *node;

for (p = 0; info->argv[p]; p++)
{
if (info->argv[p][0] != '$' || !info->argv[p][1])
continue;

if (!_strcmp(info->argv[p], "$?"))
{
replace_string(&(info->argv[p]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[p], "$$"))
{
replace_string(&(info->argv[p]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[p][1], '=');
if (node)
{
replace_string(&(info->argv[p]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[p], _strdup(""));

}
return (0);
}

/**
* replace_string - it replaces str
* @old: the ad of old str
* @new: the new str
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
