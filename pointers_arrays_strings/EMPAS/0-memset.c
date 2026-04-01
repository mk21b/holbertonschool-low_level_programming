#include "main.h"
#include <stdio.h>

/**
 *_memset-Overwrites a buffer of length with a constant
 *@s:a pointer to an address to start the buffer
 *@b:a constant
 *@n:length of the buffer
 *Return:returns the overwritten buffer
 */

char *_memset(char *s, char b, unsigned int n)
{
char *p = *s;

while (n--)
{
*p++ = b;
}
return (s);
}
