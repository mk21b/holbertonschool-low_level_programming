#include "main.h"
#include <stdio.h>

/**
*_strchr-returns a pointer to the first instance of char c in the string.
*@s:string
*@c:character
*Return:returns the pointer to first instance of c if it exists, NULL otherwise
*/

char *_strchr(char *s, char c)
{
while (*s)
{
if (*s == c)
return (s);
s++;
}
if (c == '\0')
return (s);
return (NULL);
}
