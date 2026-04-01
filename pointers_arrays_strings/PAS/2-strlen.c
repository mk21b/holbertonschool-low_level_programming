#include <stdio.h>
#include "main.h"

/**
 *_strlen-function that stops counting on the terminating character of a string
 *@s:integer
 *Return:length
 */

int _strlen(char *s)
{
int length = 0;

while (s[length] != '\0')
{
length++;
}
return (length);
}
