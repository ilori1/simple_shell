#include "shell.h"

/**
* _myenv - To  prints the current environment
* @info:  And structure containing potential arg its Used to maintain
*          constant function prototypes.
* Return: Always 0
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
* _getenv - To gets the value of an envi variable
* @info:  And structure containing potential arg its Used to maintain
* @name: env var name
*
* Return: the value (0)
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node)
{
u = starts_with(node->str, name);
if (u && *p)
return (u);
node = node->next;
}
return (NULL);
}

/**
* _mysetenv - To Initialize a new envir variable,
*              or modify an existing one
* @info:  And structure containing potential arg its Used to maintain
*         constant function prototype.
*  Return: Always 0
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
* _myunsetenv - It Removes an envir variable
* @info:  And structure containing potential arg its Used to maintain
*         constant funct prototypes.
* Return: Always 0
*/
int _myunsetenv(info_t *info)
{
int t;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (t = 1; t <= info->argc; t++)
_unsetenv(info, info->argv[t]);

return (0);
}

/**
* populate_env_list - To  populates env linked list
* @info: A structure containing potential arg its Used to maintain
*          constant function prototypes.
* Return: Always 0
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t p;

for (p = 0; environ[p]; p++)
add_node_end(&node, environ[p], 0);
info->env = node;
return (0);
}
