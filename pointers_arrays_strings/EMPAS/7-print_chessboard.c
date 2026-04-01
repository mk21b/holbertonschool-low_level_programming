#include <stdio.h>
#include "main.h"

/**
*print_chessboard-printsan 8x8 array
*@a:an 8x8 array
*/

void print_chessboard(char (*a)[8])
{
int i = 0;
int j;

while (i < 8)
{
j = 0;
while (j < 8)
{
putchar(a[i][j]);
j++;
}
putchar('\n');
i++;
}
}
