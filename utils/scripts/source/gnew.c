#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
        return (-1);

    char *dir = argv[1];
    char mkdir[256] = "mkdir ", touch[256] = "touch ./", file[256] = "/";
    char gitig[256] = "echo \"*#*\\n*~*\\n*a.out*\\n*core.*\" > ./";
    char readme[512] = "echo \"This is an incomplete Readme\" > ./";
    char md[] = "/README.md", nore[] = "/.gitignore";

    strncat(mkdir, dir, sizeof(mkdir) - strlen(mkdir) - 1);
    strncat(file, argv[2], sizeof(file) - strlen(file) - 1);
    strncat(touch, dir, sizeof(touch) - strlen(touch) - 1);
    strncat(touch, file, sizeof(touch) - strlen(touch) - 1);
    strncat(gitig, dir, sizeof(gitig) - strlen(gitig) - 1);
    strncat(gitig, nore, sizeof(gitig) - strlen(gitig) - 1);
    strncat(readme, dir, sizeof(readme) - strlen(readme) - 1);
    strncat(readme, md, sizeof(readme) - strlen(readme) - 1);

    system(mkdir);
    if (argv[2] != NULL)
        system(touch);
    system(gitig);
    system(readme);
    
    
    return (0);
}