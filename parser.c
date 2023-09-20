#include "shell.h"

/**
* is_cmd - it determines if a file is an executable command
* @info: of the info struct
* @path: apath to the file
*
* Return: 1 if true, 0 otherwise
*/
int is_cmd(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
* dup_chars - it duplicates characters
* @pathstr: of the PATH string
* @start: the starting index
* @stop: a stopping index
*
* Return: the pointer to new buffer
*/
char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024];
int p = 0, u = 0;

for (u = 0, p = start; p < stop; p++)
if (pathstr[p] != ':')
buf[u++] = pathstr[p];
buf[u] = 0;
return (buf);
}

/**
* find_path - it finds this cmd in the PATH str
* @info: of the info struct
* @pathstr: of the PATH str
* @cmd: a cmd to find
*
* Return: the full path of cmd if found or NULL
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
int p = 0, curr_pos = 0;
char *path;

if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[p] || pathstr[p] == ':')
{
path = dup_chars(pathstr, curr_pos, p);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[p])
break;
curr_pos = p;
}
p++;
}
return (NULL);
}
