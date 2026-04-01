#include "main.h"

/**
 *print_rev-prints str in reverse
 *@s:string
 */

void print_rev(char *s)
{
int length = 0;
while (s[length] != '\0')
{
length++;
}
while (length > 0)
{
length--;
_putchar(s[length]);
}
_putchar('\n');
}
