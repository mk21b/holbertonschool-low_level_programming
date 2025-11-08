#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: the string to search
 * @c: the character to locate
 *
 * Return: pointer to first occurrence of c in s, or 0 if not found
 */
char *_strchr(char *s, char c)
{
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (&s[i]);
        i++;
    }

    /* if we're looking for the null terminator, return its address */
    if (c == '\0')
        return (&s[i]);

    return (0); /* character not found */
}
