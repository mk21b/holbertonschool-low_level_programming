#include "main.h"
#include <stdio.h>

/**
*_strncpy-function changes *dest[0:i] to *src with a limit of n bytes.
*@dest:destination string.
*@src:source string.
*@n:an integer.
*Return: returns appended str.
*/

char *_strncpy(char *dest, char *src, int n)
{
int i = 0;

while ((src[i] != '\0') && (i < n))
{
dest[i] = src[i];
i++;
}
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}
