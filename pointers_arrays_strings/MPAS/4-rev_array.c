#include "main.h"
#include <stdio.h>

/**
*reverse_array-reverse prints ur array
*@a:an array
*@n:max strlen of a
*Return:void
*/

void reverse_array(int *a, int n)
{
int j = 0;
int temp;

while (j < n - 1 - j)
{
temp = a[j];
a[j] = a[n - 1 - j];
a[n - 1 - j] = temp;
j++;
}
}
