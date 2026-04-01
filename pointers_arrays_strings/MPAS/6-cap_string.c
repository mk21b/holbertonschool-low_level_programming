#include "main.h"
#include <stdio.h>

/**
*cap_string-sets  the firs letter after each separator to a capital.
*@str:input string.
*Return: returns the string.
*/

char *cap_string(char *str)
{
int i = 0;
int b = 1;

while (str[i] != '\0')
{
if (str[i] >= 'a' && str[i] <= 'z' && b == 1)
{
str[i] = str[i] - 32;
}
b = 0;

if (
str[i] == ' ' ||
str[i] == ',' ||
str[i] == ';' ||
str[i] == '.' ||
str[i] == '!' ||
str[i] == '?' ||
str[i] == '"' ||
str[i] == '(' ||
str[i] == ')' ||
str[i] == '{' ||
str[i] == '}' ||
str[i] == '\t' ||
str[i] == '\n'
)
{
b = 1;
}
i++;
}
return (str);
}
