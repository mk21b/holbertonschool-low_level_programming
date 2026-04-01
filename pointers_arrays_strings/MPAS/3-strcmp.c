#include <stdio.h>
#include "main.h"

/**
*_strcmp-compares s1 and s2
*@s1:string one
*@s2:string two
*Return:difference of last char
*/

int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
i++;
}
return (s1[i] - s2[i]);
}
