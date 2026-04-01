#include <stdio.h>
#include "main.h"

/**
 *_strcpy-function copies str from src to dest and returns the str
 *@dest:destination string
 *@src:source string
 *Return:destination string
 */

char *_strcpy(char *dest, char *src)
{
int length = 0;

while (src[length] != '\0')
{
dest[length] = src[length];
length++;
}
dest[length] = '\0';
return (dest);
}
