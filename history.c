#include "shell.h"

/**
* get_history_file - it gets the hist file
* @info: the parameter struct
*
* Return: it allocated str containg hist file
*/

char *get_history_file(info_t *info)
{
char *buf, *dir;

dir = _getenv(info, "HOME=");
if (!dir)
return (NULL);
buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buf)
return (NULL);
buf[0] = 0;
_strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, HIST_FILE);
return (buf);
}

/**
* write_history - it creates a file and appends to an existing file
* @info: a parameter struct
*
* Return: 1 on success, else -1
*/
int write_history(info_t *info)
{
ssize_t fd;
char *filename = get_history_file(info);
list_t *node = NULL;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, fd);
_putfd('\n', fd);
}
_putfd(BUF_FLUSH, fd);
close(fd);
return (1);
}

/**
* read_history - it reads hist from file
* @info: a parameter struct
*
* Return: histcount on success, 0 otherwise
*/
int read_history(info_t *info)
{
int u, last = 0, linecount = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = get_history_file(info);

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buf = malloc(sizeof(char) * (fsize + 1));
if (!buf)
return (0);
rdlen = read(fd, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
return (free(buf), 0);
close(fd);
for (u = 0; u < fsize; u++)
if (buf[u] == '\n')
{
buf[u] = 0;
build_history_list(info, buf + last, linecount++);
last = u + 1;
}
if (last != u)
build_history_list(info, buf + last, linecount++);
free(buf);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}

/**
* build_history_list - it adds entry to a hist linked list
* @info: the stru containing potential arg. Used to maintain
* @buf: buffers
* @linecount: the hist linecount, histcount
*
* Return: Always 0
*/
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);

if (!info->history)
info->history = node;
return (0);
}

/**
* renumber_history - it renumbers the hist linked list after changes
* @info: struc containing potential args. Used to maintain
*
* Return: the new histcount
*/
int renumber_history(info_t *info)
{
list_t *node = info->history;
int u = 0;

while (node)
{
node->num = u++;
node = node->next;
}
return (info->histcount = u);
}
