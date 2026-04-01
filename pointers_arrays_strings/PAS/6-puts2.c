#include <stdio.h>
#include "main.h"

/**
 *puts2-prints odd characters in a string
 *@str:string input
 */

void puts2(char *str)
{
int i = 0;

while (str[i] != '\0')
{
if (i % 2 == 0)
{
_putchar(str[i]);
}
i++;
}
_putchar('\n');
}
