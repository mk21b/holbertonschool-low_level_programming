#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *branch, confirm, c;
    char *str, msg[256];
    char add[32] = "git add *";
    char commit[512] = "git commit -m ";
    char push[512] = "git push origin ";;
    
    if (argc != 3)
        return (printf("Please use the format: gall <branch> <commit>"));

    branch = argv[1];
    str = argv[2];
    snprintf(msg, sizeof(msg), "\"%s\"", str);
    strncat(commit, msg, sizeof(commit) - strlen(commit) - 1);
    strncat(push, branch, sizeof(push) - strlen(push) - 1);

    system(add);
    system(commit);

    printf("Push to branch %s? (y/n): ", branch);
    fflush(stdout);
    do {
        c = getchar();
    } while (c == '\n');
    confirm = c;
    if (confirm == 'y' || confirm == 'Y')
        system(push);
    else
        system("git reset HEAD~3");
    return (0);
}