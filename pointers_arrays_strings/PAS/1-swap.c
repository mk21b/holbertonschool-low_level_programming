#include <stdio.h>
#include "main.h"

/**
 *swap_int-swaps integers
 *@a:integer
 *@b:integer
 */

void swap_int(int *a, int *b)
{
int c = *a;
*a = *b;
*b = c;
}
