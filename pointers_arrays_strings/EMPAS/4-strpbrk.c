#include "main.h"
#include <stdio.h>

/**
*_strpbrk-returns a pointer to the first match (x E accept) E s
*@s:a string
*@accept:a string
*Return:returns a pointer
*/

char *_strpbrk(char *s, char *accept)
{
char *a;

while (*s)
{
a = accept;
while (*a)
{
if (*a == *s)
{
return (s);
}
a++;
}
s++;
}
return (NULL);
}
