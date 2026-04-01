#include "main.h"
#include <stdio.h>

/**
*leet-transcodes a string to leet.
*@str:string.
*Return:returns the string.
*/

char *leet(char *str)
{
int i = 0;
int j;
char ltrs[] = "aAeEoOtTlL";
char leet[] = "4433007711";

while (str[i] != '\0')
{
j = 0;
while (ltrs[j] != '\0')
{
if (str[i] == ltrs[j])
{
str[i] = leet[j];
}
j++;
}
i++;
}
return (str);
}
