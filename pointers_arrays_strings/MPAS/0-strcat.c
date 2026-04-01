#include "main.h"
#include <stdio.h>

/**
*_strcat-function appends *dest to *src.
*@dest:destination string.
*@src:source string.
*Return: returns appended str.
*/

char *_strcat(char *dest, char *src)
{
char *d = dest;

while (*d != '\0')
{
d++;
}
while (*src != '\0')
{
*d++ = *src++;
}
*d = '\0';
return (dest);
}
