#include "main.h"
#include <stdio.h>

/**
*_strspn-returns a count of characters in s after the first match in accept
*@s:a string
*@accept:a string
*Return:returns the count
*/

unsigned int _strspn(char *s, char *accept)
{
int i = 0;
char *a;
int match;

while (*s)
{
a = accept;
match = 0;
while (*a)
{
if (*s == *a)
{
match = 1;
break;
}
a++;
}
if (!match)
{
return (i);
}
i++;
s++;
}
return (i);
}
