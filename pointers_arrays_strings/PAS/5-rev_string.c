#include <stdio.h>
#include "main.h"

/**
*rev_string-prints str in reverse
*@s:string
*/

void rev_string(char *s)
{
int length = 0;
int i = 0;
char temp;
while (s[length] != '\0')
{
length++;
}
while (i < length / 2)
{
temp = s[i];
s[i] = s[length - i - 1];
s[length - i - 1] = temp;
i++;
}
}
