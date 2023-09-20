#include "shell.h"

/**
* _erratoi - To converts a str to an integer
* @s: strings to be converted
* Return: 0 if no numbers in str, converted number otherwise
*       -1 on error
*/
int _erratoi(char *s)
{
int p = 0;
unsigned long int result = 0;

if (*s == '+')
s++;  /* TODO: why does this make main return 255? */
for (p = 0;  s[p] != '\0'; p++)
{
if (s[p] >= '0' && s[p] <= '9')
{
result *= 10;
result += (s[p] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
* print_error - It  prints an error message
* @info: parameters & return info struct
* @estr: str containing specified err type
* Return: 0 if no numbers in str, converted number otherwise
*        -1 on error
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
* print_d - The func. prints a decimal (int) number (base 10)
* @input: the inputs
* @fd: the filedescrip to write to
*
* Return: number of characters printed
*/
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int y, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (y = 1000000000; y > 1; y /= 10)
{
if (_abs_ / y)
{
__putchar('0' + current / y);
count++;
}
current %= y;
}
__putchar('0' + current);
count++;

return (count);
}

/**
* convert_number - The converter func, a clone of itoa
* @num: numbers
* @base: bases
* @flags: argument flags
*
* Return: string
*/
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';

}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do	{
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
* remove_comments - The func. replaces first instance of '#' with '\0'
* @buf: an address of the str to modify
*
* Return: Always 0;
*/
void remove_comments(char *buf)
{
int k;

for (k = 0; buf[k] != '\0'; k++)
if (buf[k] == '#' && (!k || buf[k - 1] == ' '))
{
buf[k] = '\0';
break;
}
}
