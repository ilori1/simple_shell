#include "shell.h"

/**
* list_len - it determines length of linked list
* @h: of the pointer to first node
*
* Return: the size of the list
*/
size_t list_len(const list_t *h)
{
size_t y = 0;

while (h)
{
h = h->next;
y++;
}
return (y);
}

/**
* list_to_strings - it returns an array of strings of the list->str
* @head: the pointer to first node
*
* Return: an array of str
*/
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t d = list_len(head), j;
char **strs;
char *str;

if (!head || !d)
return (NULL);
strs = malloc(sizeof(char *) * (d + 1));
if (!strs)
return (NULL);
for (d = 0; node; node = node->next, d++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < d; j++)
free(strs[j]);
free(strs);
return (NULL);
}

str = _strcpy(str, node->str);
strs[d] = str;
}
strs[d] = NULL;
return (strs);
}


/**
* print_list - it prints all elements of a list_t linked list
* @h: the pointer to first node
*
* Return: the size of the list
*/
size_t print_list(const list_t *h)
{
size_t y = 0;

while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
y++;
}
return (y);
}

/**
* node_starts_with - it returns node whose str starts with prefix
* @node: of the pointer to list head
* @prefix: the strs to match
* @c: next char after prefix to match
*
* Return: the match node or null
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *prefix = NULL;

while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}

/**
* get_node_index - it gets the index of a node
* @head: the pointer to list head
* @node: a pointer to the node
*
* Return: index of node or -1
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t f = 0;

while (head)
{
if (head == node)
return (f);
head = head->next;
f++;
}
return (-1);
}
