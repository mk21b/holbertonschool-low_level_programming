#include "holberton.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to new string, NULL if it fails
 */

char *str_concat(char *s1, char *s2)
{
    int length1, length2, length3, i;
    char *arr;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    length1 = 0;
    while (*(s1 + length1) != '\0')
    {
        length1++;
    }

    length2 = 0;
    while (*(s2 + length2) != '\0')
    {
        length2++;
    }

    length3 = length1 + length2 + 1; // +1 for the null terminator

    arr = (char*) malloc(length3 * sizeof(char)); // No need to multiply by sizeof(char), it's 1
    if (arr == NULL)
        return (NULL);

    // Copy s1 into arr
    for (i = 0; i < length1; i++)
        arr[i] = s1[i];

    // Copy s2 into arr right after s1
    for (i = 0; i < length2; i++)
        arr[i + length1] = s2[i];

    // Null terminate the concatenated string
    arr[length3 - 1] = '\0';

    return (arr);
}

