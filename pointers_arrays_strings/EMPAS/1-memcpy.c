#include "main.h"
#include <stdio.h>

/**
 *_memcpy-copies a buffer from source to dest with length n
 *@dest:destination buffer
 *@src:source buffer
 *@n:length of the buffer
 *Return:returns the original buffer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
char *original = dest;

while (n--)
{
*dest++ = *src++;
}
return (original);
}
