#include <main.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * checker - checks if all arguments are positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if valid, 1 if any invalid
 */
int checker(int argc, char *argv[])
{
    int i, j;
    for (i = 1; i < argc; i++)
    {
        for (j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
                return 1;
        }
    }
    return 0;
}

/**
 * main - adds all positive numbers passed as arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
    int i, result = 0;

    if (checker(argc, argv))
    {
        printf("Error\n");
        return 1;
    }

    for (i = 1; i < argc; i++)
        result += atoi(argv[i]);

    printf("%d\n", result);
    return 0;
}
