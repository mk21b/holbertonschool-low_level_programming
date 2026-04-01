#include "main.h"
#include <stdio.h>

/**
*print_diagsums-sums forward and reverse diagonals of a square array
*@a:an array
*@size:height/width of array
*/

void print_diagsums(int *a, int size)
{
int i = 0;
int sum1 = 0, sum2 = 0;

while (i < size)
{
sum1 += a[i * size + i];
sum2 += a[i * size + (size - 1 - i)];
i++;
}
printf("%d, %d\n", sum1, sum2);
}
