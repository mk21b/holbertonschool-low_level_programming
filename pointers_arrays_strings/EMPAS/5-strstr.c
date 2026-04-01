#include "main.h"
#include <stdio.h>

/**
*_strstr-function points to the first matching instance of needle in haystack
*@haystack:a string
*@needle:a string
*Return:returns pointer to the first instance match
*/

char *_strstr(char *haystack, char *needle)
{
char *n;
int ln = 0; /** length of needle */
int match;
char *h;
char *start;

while (*needle)
{
ln++;
needle++;
}
needle -= ln;

while (*haystack)
{
h = haystack;
n = needle;
match = 0;
while (*n)
{
if (*h == *n)
{
match++;
}
n++;
h++;
}
if (match == ln)
{
start = h - ln;
return (start);
}
haystack++;
}
return (NULL);
}
